
#ifndef CRC8_HPP
#define CRC8_HPP

#include <QStringList>
#include <QDebug>

/*!
*   \file
*   \brief Plik nagłówkowy dla CRC8.cpp
*/

#define POLYNOMIAL_9 0x0161 //!< Wielomian potrzebny do obliczenia sumy kontrolnej
typedef unsigned char byte; //!< Definicja typu byte

/*!
*   \brief CRC8 dla pojedynczego bajtu
*   \param[in,out] Data2 - przetwarzany bajt
*   \return sumę kontrolną
*/
unsigned int CRC8_SingleByte(unsigned int Data2);

/*!
*   \brief CRC8 dla ramki danych.
*   \param[in] pDataFrame - wskaźnik na ramkę danych
*   \param[in] Len - długość ramki
*   \return sumę kontrolną
*
*/
byte CRC8_DataArray(const byte *pDataFrame, byte Len);


/*!
*   \brief Podział ramki danych.
*
*   Podział ramki na poszczególne elementy i sprawdzenie jej poprawności - nagłówek, suma kontrolna.
*
*   \param[in] DataFrame - ramka danych
*
*   \param[out] sensors - tablica, do której zostaną zapisane odczyty z czujników
*
*   \return
*   <c>True</c> - jeśli ramka jest poprawna
*   <c>False</c> - jeśli ramka jest uszkodzona
*/
bool ParseDataFrame( QString DataFrame, int sensors[4]);

#endif // CRC8_HPP
