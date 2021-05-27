#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "CRC8.hpp"
#include "Settings.hpp"


/*!
*   \file
*   \brief Implementacja metod klasy MainWindow
*/



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    //Ustawienia
    dial=new Settings();
    dial->setWindowTitle("Ustawienia");

    connect(dial, SIGNAL(Connection()), this, SLOT(ledOn()));
    connect(dial, SIGNAL(Disconnection()), this, SLOT(ledOff()));

    //LED
    ui->graphicsView_LED->setScene(new QGraphicsScene());
    ui->graphicsView_LED->setBackgroundBrush(QBrush(QColor(255,0,0)));


    /************** LEGENDA ************/

    QColor Green = QColor(0,220,50);
    QColor Yellow = QColor(255,240,0);
    QColor Orange = QColor(255,165,0);
    QColor Red = QColor(250,0,0);

    ui->graphicsView_Legend_1->setScene(new QGraphicsScene());
    ui->graphicsView_Legend_2->setScene(new QGraphicsScene());
    ui->graphicsView_Legend_3->setScene(new QGraphicsScene());
    ui->graphicsView_Legend_4->setScene(new QGraphicsScene());


    ui->graphicsView_Legend_1->setBackgroundBrush(QBrush(Green));
    ui->graphicsView_Legend_2->setBackgroundBrush(QBrush(Yellow));
    ui->graphicsView_Legend_3->setBackgroundBrush(QBrush(Orange));
    ui->graphicsView_Legend_4->setBackgroundBrush(QBrush(Red));

    on_spinBox_valueChanged(120);
    on_spinBox_2_valueChanged(60);
    on_spinBox_3_valueChanged(30);


    /************ AUTO ***************/

    waves=new Waves();
    ui->graphicsView->setScene( waves->getScene() );

    QGraphicsScene * scene2 = new QGraphicsScene(150,70,100,100);
    scene2->addPixmap(QPixmap( "auto.jpg" ).scaled(400,400));
    ui->graphicsView_2->setScene( scene2 );



    /*************** WYKRESY **************/

    QString titles [4]={"Czujnik Lewy","Czujnik Centralny Lewy","Czujnik Centralny Prawy","Czujnik Prawy"};
    for(int i=0;i<4;++i) chart[i] = new Chart(titles[i]);

    ui->gridLayout_4->addWidget(chart[0]->getChartView());
    ui->gridLayout_5->addWidget(chart[1]->getChartView());
    ui->gridLayout_6->addWidget(chart[2]->getChartView());
    ui->gridLayout_7->addWidget(chart[3]->getChartView());
}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::readFromPort()
{
    int czujniki[4];
    while(dial->Device()->canReadLine()) {
       QString ramka = dial->Device()->readLine();
       if(ParseDataFrame(ramka,czujniki)){
       qDebug()<<"Prawidłowa ramka";
       chart[0]->addPoint(chart[0]->PointCounter(), czujniki[0]);
       chart[1]->addPoint(chart[1]->PointCounter(), czujniki[1]);
       chart[2]->addPoint(chart[2]->PointCounter(), czujniki[2]);
       chart[3]->addPoint(chart[3]->PointCounter(), czujniki[3]);
       waves->setColour(czujniki,ranges);
       ui->lcdNumber_L->display(czujniki[0]);
       ui->lcdNumber_CL->display(czujniki[1]);
       ui->lcdNumber_CP->display(czujniki[2]);
       ui->lcdNumber_P->display(czujniki[3]);
       }
     }
}


void MainWindow::on_pushButton_Settings_clicked()
{
    this->dial->show();
}


void MainWindow::ledOn()
{
    ui->graphicsView_LED->setBackgroundBrush(QBrush(QColor(0,255,0)));
    connect(dial->Device(), SIGNAL(readyRead()), this, SLOT(readFromPort()));
}



void MainWindow::ledOff()
{
    ui->graphicsView_LED->setBackgroundBrush(QBrush(QColor(255,0,0)));
}

void MainWindow::on_spinBox_valueChanged(int val)
{
    ui->spinBox->setValue(val);
    ui->spinBox_2->setMaximum(val);
    ranges[0]=val;
}

void MainWindow::on_spinBox_2_valueChanged(int val)
{
    ui->spinBox_2->setValue(val);
    ui->spinBox_3->setMaximum(val);
    ranges[1]=val;
}

void MainWindow::on_spinBox_3_valueChanged(int val)
{
    ui->spinBox_3->setValue(val);
    ranges[2]=val;
}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    QTransform rotate;
    rotate.rotate(value);
    ui->graphicsView->setTransform(rotate);
}
