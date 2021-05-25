#include "Waves.h"


/*!
*   \file
*   \brief Implementacja metod klasy Waves
*/

/*!
 * \brief Konstruktor klasy.
 *
 * Wyrysowuje obraz samochodu i fale ultradźwiękowe w kolorze białym - nie rzucające się w oczy.
 */

Waves::Waves()
{
    scene = new QGraphicsScene();
    scene->addPixmap( QPixmap( "auto.jpg" ) );
    QPen rysuj (QColor(250,250,250),3);
/*
   line1= scene->addLine(110, 0, 160, 0, rysuj);
   line3 =scene->addLine(110, -50, 160, -50,rysuj);
   line2= scene->addLine(110, -25, 160, -25,rysuj);
   line4 =scene->addLine(110, -75, 160, -75,rysuj);

   line5= scene->addLine(170, 0, 220, 0, rysuj);
   line7 =scene->addLine(170, -50, 220, -50,rysuj);
   line6= scene->addLine(170, -25, 220, -25,rysuj);
   line8 =scene->addLine(170, -75, 220, -75,rysuj);

   line10= scene->addLine(50, 0, 100, 0, rysuj);
   line12 =scene->addLine(50, -50, 100, -50,rysuj);
   line11= scene->addLine(50, -25, 100, -25,rysuj);
   line9 =scene->addLine(50, 25, 100, 25,rysuj);

   line14= scene->addLine(230, 0, 280, 0, rysuj);
   line16 =scene->addLine(230, -50, 280, -50,rysuj);
   line15= scene->addLine(230, -25, 280, -25,rysuj);
   line13= scene->addLine(230, 25, 280, 25,rysuj);
*/
   lines1[0] = scene->addLine(110, 0, 160, 0, rysuj);
   lines1[1] = scene->addLine(110, -25, 160, -25,rysuj);
   lines1[2] = scene->addLine(110, -50, 160, -50,rysuj);
   lines1[3] = scene->addLine(110, -75, 160, -75,rysuj);

   lines[0]=lines1;

   lines2[0] = scene->addLine(170, 0, 220, 0, rysuj);
   lines2[1] = scene->addLine(170, -25, 220, -25,rysuj);
   lines2[2] = scene->addLine(170, -50, 220, -50,rysuj);
   lines2[3] = scene->addLine(170, -75, 220, -75,rysuj);

   lines[1]=lines2;

   lines3[0] =scene->addLine(50, 25, 100, 25,rysuj);
   lines3[1] = scene->addLine(50, 0, 100, 0, rysuj);
   lines3[2] = scene->addLine(50, -25, 100, -25,rysuj);
   lines3[3] =scene->addLine(50, -50, 100, -50,rysuj);

   lines[2]=lines3;

   lines4[0]= scene->addLine(230, 25, 280, 25,rysuj);
   lines4[1]= scene->addLine(230, 0, 280, 0, rysuj);
   lines4[2]= scene->addLine(230, -25, 280, -25,rysuj);
   lines4[3] =scene->addLine(230, -50, 280, -50,rysuj);

   lines[3]=lines4;




}



/*!
 *  \brief Zmiana koloru fal
 *
 *  W zależności od odległości od przeskody koloruje odpowiednio fale wychodzące z czujników.
 *  \param sensors - tabela z odczytami odległości z czujników
 */

void Waves::setColour(int sensors[])
{
QColor Gray = QColor(240,240,240);
QColor Green = QColor(0,220,50);
QColor Yellow = QColor(255,240,0);
QColor Orange = QColor(255,165,0);
QColor Red = QColor(250,0,0);
int line_width=8;
    for(int i=0;i<4;++i){
        if(sensors[i]==200){
            lines[i][0] ->setPen(QPen(Gray,line_width));
            lines[i][1] ->setPen(QPen(Gray,line_width));
            lines[i][2] ->setPen(QPen(Gray,line_width));
            lines[i][3] ->setPen(QPen(Gray,line_width));
        }
    else if(sensors[i]>120){

lines[i][0] ->setPen(QPen(Gray,line_width));
lines[i][1] ->setPen(QPen(Gray,line_width));
lines[i][2] ->setPen(QPen(Gray,line_width));
lines[i][3] ->setPen(QPen(Green,line_width));

    }
    else if(sensors[i]>60){
        lines[i][0]->setPen(QPen(Gray,line_width));
        lines[i][1] ->setPen(QPen(Gray,line_width));
        lines[i][2]->setPen(QPen(Yellow,line_width));
        lines[i][3]->setPen(QPen(Gray,line_width));
    }
    else if(sensors[i]>30){
       lines[i][0]->setPen(QPen(Gray,line_width));
       lines[i][1] ->setPen(QPen(Orange,line_width));
       lines[i][2]->setPen(QPen(Gray,line_width));
        lines[i][3]->setPen(QPen(Gray,line_width));
    }
    else {
        lines[i][0]->setPen(QPen(Red,line_width));
        lines[i][1] ->setPen(QPen(Gray,line_width));
        lines[i][2]->setPen(QPen(Gray,line_width));
       lines[i][3]->setPen(QPen(Gray,line_width));
    }

}



/*
    if(sensors[0]>120){

lines4[0] ->setPen(QPen(QColor(0,220,50),10));
lines4[1] ->setPen(QPen(QColor(0,220,50),10));
lines4[2] ->setPen(QPen(QColor(0,220,50),10));
lines4[3] ->setPen(QPen(QColor(0,0,0),15));

    }
    else if(sensors[0]>60){
        lines4[0]->setPen(QPen(QColor(255,240,0),3));
        lines4[1] ->setPen(QPen(QColor(255,240,0),3));
        lines4[2]->setPen(QPen(QColor(255,240,0),3));
        lines4[3]->setPen(QPen(QColor(230,230,230),3));
    }
    else if(sensors[0]>30){
       lines4[0]->setPen(QPen(QColor(255,165,0),3));
       lines4[1] ->setPen(QPen(QColor(255,165,0),3));
       lines4[2]->setPen(QPen(QColor(230,230,230),3));
        lines4[3]->setPen(QPen(QColor(230,230,230),3));
    }
    else {
        lines4[0]->setPen(QPen(QColor(250,0,0),3));
        lines4[1] ->setPen(QPen(QColor(230,230,230),3));
        lines4[2]->setPen(QPen(QColor(230,230,230),3));
       lines4[3]->setPen(QPen(QColor(230,230,230),3));
    }

    if(sensors[3]>120){

lines3[0] ->setPen(QPen(QColor(0,220,50),3));
lines3[1] ->setPen(QPen(QColor(0,220,50),3));
lines3[2]->setPen(QPen(QColor(0,220,50),3));
lines3[3]->setPen(QPen(QColor(0,220,50),3));

    }
    else if(sensors[3]>60){
        lines3[0]->setPen(QPen(QColor(255,240,0),3));
        lines3[1] ->setPen(QPen(QColor(255,240,0),3));
        lines3[2]->setPen(QPen(QColor(255,240,0),3));
        lines3[3]->setPen(QPen(QColor(230,230,230),3));
    }
    else if(sensors[3]>30){
        lines3[0]->setPen(QPen(QColor(255,165,0),3));
        lines3[1] ->setPen(QPen(QColor(255,165,0),3));
        lines3[2]->setPen(QPen(QColor(230,230,230),3));
        lines3[3]->setPen(QPen(QColor(230,230,230),3));
    }
    else {
        lines3[0]->setPen(QPen(QColor(250,0,0),3));
        lines3[1] ->setPen(QPen(QColor(230,230,230),3));
        lines3[2]->setPen(QPen(QColor(230,230,230),3));
        lines3[3]->setPen(QPen(QColor(230,230,230),3));
    }


    if(sensors[1]>120){

lines2[0] ->setPen(QPen(QColor(0,220,50),3));
lines2[1] ->setPen(QPen(QColor(0,220,50),3));
lines2[2]->setPen(QPen(QColor(0,220,50),3));
lines2[3]->setPen(QPen(QColor(0,220,50),3));

    }
    else if(sensors[1]>60){
        lines2[0]->setPen(QPen(QColor(255,240,0),3));
       lines2[1] ->setPen(QPen(QColor(255,240,0),3));
        lines2[2]->setPen(QPen(QColor(255,240,0),3));
        lines2[3]->setPen(QPen(QColor(230,230,230),3));
    }
    else if(sensors[1]>30){
        lines2[0]->setPen(QPen(QColor(255,165,0),3));
        lines2[1] ->setPen(QPen(QColor(255,165,0),3));
        lines2[2]->setPen(QPen(QColor(230,230,230),3));
        lines2[3]->setPen(QPen(QColor(230,230,230),3));
    }
    else {
        lines2[0]->setPen(QPen(QColor(250,0,0),3));
        lines2[1] ->setPen(QPen(QColor(230,230,230),3));
        lines2[2]->setPen(QPen(QColor(230,230,230),3));
        lines2[3]->setPen(QPen(QColor(230,230,230),3));
    }

    if(sensors[2]>120){

lines1[0] ->setPen(QPen(QColor(0,220,50),3));
lines1[1] ->setPen(QPen(QColor(0,220,50),3));
lines1[2]->setPen(QPen(QColor(0,220,50),3));
lines1[3]->setPen(QPen(QColor(0,220,50),3));

    }
    else if(sensors[2]>60){
        lines1[0]->setPen(QPen(QColor(255,240,0),3));
        lines1[1] ->setPen(QPen(QColor(255,240,0),3));
        lines1[2]->setPen(QPen(QColor(255,240,0),3));
        lines1[3]->setPen(QPen(QColor(230,230,230),3));
    }
    else if(sensors[2]>30){
        lines1[0]->setPen(QPen(QColor(255,165,0),3));
        lines1[1] ->setPen(QPen(QColor(255,165,0),3));
        lines1[2]->setPen(QPen(QColor(230,230,230),3));
        lines1[3]->setPen(QPen(QColor(230,230,230),3));
    }
    else {
        lines1[0]->setPen(QPen(QColor(250,0,0),3));
        lines1[1] ->setPen(QPen(QColor(230,230,230),3));
        lines1[2]->setPen(QPen(QColor(230,230,230),3));
        lines1[3]->setPen(QPen(QColor(230,230,230),3));
    }
*/
/*
    if(sensors[0]>120){

line13 ->setPen(QPen(QColor(0,220,50),10));
line14 ->setPen(QPen(QColor(0,220,50),10));
line15->setPen(QPen(QColor(0,220,50),10));
line16->setPen(QPen(QColor(0,0,0),15));

    }
    else if(sensors[0]>60){
        line13->setPen(QPen(QColor(255,240,0),3));
        line14 ->setPen(QPen(QColor(255,240,0),3));
        line15->setPen(QPen(QColor(255,240,0),3));
        line16->setPen(QPen(QColor(230,230,230),3));
    }
    else if(sensors[0]>30){
        line13->setPen(QPen(QColor(255,165,0),3));
        line14 ->setPen(QPen(QColor(255,165,0),3));
        line15->setPen(QPen(QColor(230,230,230),3));
        line16->setPen(QPen(QColor(230,230,230),3));
    }
    else {
        line13->setPen(QPen(QColor(250,0,0),3));
        line14 ->setPen(QPen(QColor(230,230,230),3));
        line15->setPen(QPen(QColor(230,230,230),3));
        line16->setPen(QPen(QColor(230,230,230),3));
    }

    if(sensors[3]>120){

line9 ->setPen(QPen(QColor(0,220,50),3));
line10 ->setPen(QPen(QColor(0,220,50),3));
line11->setPen(QPen(QColor(0,220,50),3));
line12->setPen(QPen(QColor(0,220,50),3));

    }
    else if(sensors[3]>60){
        line9->setPen(QPen(QColor(255,240,0),3));
        line10 ->setPen(QPen(QColor(255,240,0),3));
        line11->setPen(QPen(QColor(255,240,0),3));
        line12->setPen(QPen(QColor(230,230,230),3));
    }
    else if(sensors[3]>30){
        line9->setPen(QPen(QColor(255,165,0),3));
        line10 ->setPen(QPen(QColor(255,165,0),3));
        line11->setPen(QPen(QColor(230,230,230),3));
        line12->setPen(QPen(QColor(230,230,230),3));
    }
    else {
        line9->setPen(QPen(QColor(250,0,0),3));
        line10 ->setPen(QPen(QColor(230,230,230),3));
        line11->setPen(QPen(QColor(230,230,230),3));
        line12->setPen(QPen(QColor(230,230,230),3));
    }


    if(sensors[1]>120){

line5 ->setPen(QPen(QColor(0,220,50),3));
line6 ->setPen(QPen(QColor(0,220,50),3));
line7->setPen(QPen(QColor(0,220,50),3));
line8->setPen(QPen(QColor(0,220,50),3));

    }
    else if(sensors[1]>60){
        line5->setPen(QPen(QColor(255,240,0),3));
        line6 ->setPen(QPen(QColor(255,240,0),3));
        line7->setPen(QPen(QColor(255,240,0),3));
        line8->setPen(QPen(QColor(230,230,230),3));
    }
    else if(sensors[1]>30){
        line5->setPen(QPen(QColor(255,165,0),3));
        line6 ->setPen(QPen(QColor(255,165,0),3));
        line7->setPen(QPen(QColor(230,230,230),3));
        line8->setPen(QPen(QColor(230,230,230),3));
    }
    else {
        line5->setPen(QPen(QColor(250,0,0),3));
        line6 ->setPen(QPen(QColor(230,230,230),3));
        line7->setPen(QPen(QColor(230,230,230),3));
        line8->setPen(QPen(QColor(230,230,230),3));
    }

    if(sensors[2]>120){

line1 ->setPen(QPen(QColor(0,220,50),3));
line2 ->setPen(QPen(QColor(0,220,50),3));
line3->setPen(QPen(QColor(0,220,50),3));
line4->setPen(QPen(QColor(0,220,50),3));

    }
    else if(sensors[2]>60){
        line1->setPen(QPen(QColor(255,240,0),3));
        line2 ->setPen(QPen(QColor(255,240,0),3));
        line3->setPen(QPen(QColor(255,240,0),3));
        line4->setPen(QPen(QColor(230,230,230),3));
    }
    else if(sensors[2]>30){
        line1->setPen(QPen(QColor(255,165,0),3));
        line2 ->setPen(QPen(QColor(255,165,0),3));
        line3->setPen(QPen(QColor(230,230,230),3));
        line4->setPen(QPen(QColor(230,230,230),3));
    }
    else {
        line1->setPen(QPen(QColor(250,0,0),3));
        line2 ->setPen(QPen(QColor(230,230,230),3));
        line3->setPen(QPen(QColor(230,230,230),3));
        line4->setPen(QPen(QColor(230,230,230),3));
    }*/
}


/*!
 * \brief Metoda zwracająca wyrysowaną scenę
 */

QGraphicsScene *Waves::getScene()
{
    return scene;
}
