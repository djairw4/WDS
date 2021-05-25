#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CRC8.hpp"
#include "Settings.h"


/*!
*   \file
*   \brief Implementacja metod klasy MainWindow
*/

/*!
 * \brief Konstruktor klasy.
 *
 *  Tworzy główne okno aplikacji
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dial(new Settings())

{
    ui->setupUi(this);

    connect(dial, SIGNAL(Connection()), this, SLOT(ledOn()));
    connect(dial, SIGNAL(Disconnection()), this, SLOT(ledOff()));


    QColor Green (0,220,50);
    QColor Yellow (255,240,0);
    QColor Orange (255,165,0);
    QColor Red (250,0,0);

   // graphicsScene = new QGraphicsScene(ui->graphicsView_LED);
ui->graphicsView_LED->setScene(new QGraphicsScene());
ui->graphicsView_LED_2->setScene(new QGraphicsScene());
ui->graphicsView_LED_3->setScene(new QGraphicsScene());
ui->graphicsView_LED_4->setScene(new QGraphicsScene());
ui->graphicsView_LED_5->setScene(new QGraphicsScene());

 ui->graphicsView_LED_2->setBackgroundBrush(QBrush(Green));
 ui->graphicsView_LED_3->setBackgroundBrush(QBrush(Yellow));
 ui->graphicsView_LED_4->setBackgroundBrush(QBrush(Orange));
 ui->graphicsView_LED_5->setBackgroundBrush(QBrush(Red));

 on_spinBox_valueChanged(120);
 on_spinBox_2_valueChanged(60);

    waves=new Waves();
    ui->graphicsView->setScene( waves->getScene() );

    dial->setWindowTitle("Ustawienia");

    QGraphicsScene * scene2 = new QGraphicsScene(118,45,100,100);
   // QPixmap samochod = QPixmap( "auto.jpg" ) ;
   // samochod.scaled(10,10);
    scene2->addPixmap(QPixmap( "auto.jpg" ) );
    ui->graphicsView_2->setScene( scene2 );

    ui->graphicsView_LED->setBackgroundBrush(QBrush(QColor(255,0,0)));

    QString titles [4]={"Czujnik Lewy","Czujnik Centralny Lewy","Czujnik Centralny Prawy","Czujnik Prawy"};
    for(int i=0;i<4;++i) chart[i] = new Chart(titles[i]);
/*
    chart = new Chart();
    Chart* chart1= new Chart();
    Chart* chart2= new Chart();
    Chart* chart3= new Chart();*/
   // Chart* chart4= new Chart();
    ui->gridLayout_4->addWidget(chart[0]->getChartView());
    ui->gridLayout_5->addWidget(chart[1]->getChartView());
    ui->gridLayout_6->addWidget(chart[2]->getChartView());
    ui->gridLayout_7->addWidget(chart[3]->getChartView());
   // ui->gridLayout_8->addWidget(chart4->getChartView());



}


/*!
 * \brief Destruktor klasy.
 */
MainWindow::~MainWindow()
{
    delete ui;
}


/*!
 * \brief Czytanie z portu szeregowego
 *
 * Odczytuje dane z portu szeregowego, sprawdza czy ramka jest poprawna, jeśli tak to dodaje punkty do wykresu
 * i wyświetla pomiary z czujników
 */
void MainWindow::readFromPort()
{
    int czujniki[4];
    while(dial->device->canReadLine()) {
       QString ramka = dial->device->readLine();
       if(ParseDataFrame(ramka,czujniki)){
       qDebug()<<"Prawidłowa ramka";
       chart[0]->addPoint(chart[0]->PointCounter(), czujniki[0]);
       chart[1]->addPoint(chart[1]->PointCounter(), czujniki[1]);
       chart[2]->addPoint(chart[2]->PointCounter(), czujniki[2]);
       chart[3]->addPoint(chart[3]->PointCounter(), czujniki[3]);
       waves->setColour(czujniki,zakresy);
       ui->lcdNumber_L->display(czujniki[0]);
       ui->lcdNumber_CL->display(czujniki[1]);
       ui->lcdNumber_CP->display(czujniki[2]);
       ui->lcdNumber_P->display(czujniki[3]);
       }
     }
}

/*!
 * \brief Otwieranie okna ustawień.
 */
void MainWindow::on_pushButton_Settings_clicked()
{
    this->dial->show();
}

/*!
 * \brief Zapalanie diody LED
 *
 * Zapala diodę informującą o statusie połączenia oraz uruchamia odczyt danych.
 */
void MainWindow::ledOn()
{
    ui->graphicsView_LED->setBackgroundBrush(QBrush(QColor(0,255,0)));
    connect(dial->device, SIGNAL(readyRead()), this, SLOT(readFromPort()));
}


/*!
 * \brief Gaszenie diody LED
 *
 * Gasi diodę informującą o statusie połączenia,a dokładniej zmienia jej kolor na czerwony
 */
void MainWindow::ledOff()
{
    ui->graphicsView_LED->setBackgroundBrush(QBrush(QColor(255,0,0)));
}

void MainWindow::on_spinBox_valueChanged(int val)
{
    ui->spinBox->setValue(val);
    ui->spinBox_2->setMaximum(val);
    zakresy[0]=val;
}

void MainWindow::on_spinBox_2_valueChanged(int val)
{
    ui->spinBox_2->setValue(val);
    ui->spinBox_3->setMaximum(val);
    zakresy[1]=val;
}

void MainWindow::on_spinBox_3_valueChanged(int val)
{
    ui->spinBox_3->setValue(val);
    zakresy[2]=val;
}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    QTransform rotate;
       rotate.rotate(value);
        ui->graphicsView->setTransform(rotate);
}
