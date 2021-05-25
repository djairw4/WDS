#include "CRC8.hpp"

/*!
*   \file
*   \brief Implementacja funkcji obsługujących sumę kontrolną
*/


/*!
*   \brief CRC8 dla pojedynczego bajtu
*
*   \param Data2 - przetwarzany bajt
*
*   \return sumę kontrolną
*/
unsigned int CRC8_SingleByte(unsigned int Data2) {
    unsigned int Poly = ( POLYNOMIAL_9 << 7);
    for (int Idx = 0; Idx < 8; ++Idx) {
        if ((Data2 & 0x8000) != 0)
            Data2 ^= Poly;
        Data2 <<= 1;
    }
    return Data2;
}

/*!
*   \brief CRC8 dla ramki danych.
*
*   \param pDataFrame - wskaźnik na ramkę danych
*
*   \param Len - długość ramki
*
*   \return sumę kontrolną
*
*/
byte CRC8_DataArray(const byte *pDataFrame, byte Len) {
    unsigned int Data2 = pDataFrame[0] << 8;

    for (unsigned int Idx = 1; Idx < Len; ++Idx) {
        Data2 |= pDataFrame[Idx];
        Data2 = CRC8_SingleByte(Data2);
    }
    Data2 = CRC8_SingleByte(Data2);
    return (byte) (Data2 >> 8);
}


/*!
*   \brief Podział ramki danych.
*
*   Podział ramki na poszczególne elementy i sprawdzenie jej poprawności - nagłówek, suma kontrolna.
*
*   \param DataFrame - ramka danych
*
*   \param sensors - tablica, do której zostaną zapisane odczyty z czujników
*
*   \return
*   true - jeśli ramka jest poprawna
*   false - jeśli ramka jest uszkodzona
*/
bool ParseDataFrame( QString DataFrame, int sensors[]){
    QStringList list = DataFrame.split(' ');
    qDebug() << list;
    //konwersja danych do tablicy unsigned char
    byte table [9];
    table[0]=(byte)list.at(0).at(0).toLatin1();
    for(int i=2;i<9;i+=2){
     table[i-1]=' ';
     table[i]=(byte)list.at(i/2).toUShort();
    }
    sensors[0]=list.at(1).toInt();
    sensors[1]=list.at(2).toInt();
    sensors[2]=list.at(3).toInt();
    sensors[3]=list.at(4).toInt();
    return list.at(0)=='#'&&CRC8_DataArray(table,9)==list.at(5).toUShort(nullptr,16);
}
