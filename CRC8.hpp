
#ifndef CRC8_H
#define CRC8_H

#include "mainwindow.h"


/*!
*   \file
*   \brief Plik nagłówkowy dla CRC8.cpp
*/

#define POLYNOMIAL_9 0x0161
typedef unsigned char byte;

unsigned int CRC8_SingleByte(unsigned int Data2);

byte CRC8_DataArray(const byte *pDataFrame, byte Len);

bool ParseDataFrame( QString DataFrame, int sensors[]);

#endif // CRC8_H
