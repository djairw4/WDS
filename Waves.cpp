#include "Waves.hpp"


/*!
*   \file
*   \brief Implementacja metod klasy Waves
*/



Waves::Waves()
{
    scene = new QGraphicsScene();
    scene->addPixmap( QPixmap( "auto.jpg" ).scaled(385,385) );
    QPen rysuj (QColor(240,240,240),8);

    int x_start=77, y_start=25, length=50, x_gap=10, y_gap=-25;

    for (int i=0;i<4;++i){
        for(int j=0;j<4;++j){
           lines[i][j]= scene->addLine(x_start+i*(x_gap+length), y_start+j*y_gap, x_start+length+i*(x_gap+length), y_start+j*y_gap, rysuj);
        }
    }
}


void Waves::setColour(int sensors[4],int ranges[3])
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
         else if(sensors[i]>ranges[0]){

            lines[i][0] ->setPen(QPen(Gray,line_width));
            lines[i][1] ->setPen(QPen(Gray,line_width));
            lines[i][2] ->setPen(QPen(Gray,line_width));
            lines[i][3] ->setPen(QPen(Green,line_width));

        }
        else if(sensors[i]>ranges[1]){
            lines[i][0]->setPen(QPen(Gray,line_width));
            lines[i][1] ->setPen(QPen(Gray,line_width));
            lines[i][2]->setPen(QPen(Yellow,line_width));
            lines[i][3]->setPen(QPen(Gray,line_width));
        }
        else if(sensors[i]>ranges[2]){
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

}


QGraphicsScene *Waves::getScene()
{
    return scene;
}
