#ifndef WAVES_H
#define WAVES_H

#include <QGraphicsLineItem>
#include <QGraphicsScene>

/*!
*   \file
*   \brief Plik nagłówkowy klasy Waves
*/

/*!
    \class Waves
    \brief Klasa definiuje obraz samochodu wraz z emitowanymi falami ultradźwiękowymi.
*/

class Waves
{
public:

    Waves();
    void setColour(int sensors[],int ranges[]);
    QGraphicsScene * getScene();
private:
    QGraphicsScene * scene;

    QGraphicsLineItem* lines1 [4];
    QGraphicsLineItem* lines2 [4];
    QGraphicsLineItem* lines3 [4];
    QGraphicsLineItem* lines4 [4];

    QGraphicsLineItem* lines [4][4];

    QGraphicsLineItem * line1;
    QGraphicsLineItem * line2;
    QGraphicsLineItem * line3;
    QGraphicsLineItem * line4;

    QGraphicsLineItem * line5;
    QGraphicsLineItem * line6;
    QGraphicsLineItem * line7;
    QGraphicsLineItem * line8;

    QGraphicsLineItem * line9;
    QGraphicsLineItem * line10;
    QGraphicsLineItem * line11;
    QGraphicsLineItem * line12;

    QGraphicsLineItem * line13;
    QGraphicsLineItem * line14;
    QGraphicsLineItem * line15;
    QGraphicsLineItem * line16;

};

#endif // WAVES_H
