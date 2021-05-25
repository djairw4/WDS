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

    graphicsScene = new QGraphicsScene(ui->graphicsView_LED);
    ui->graphicsView_LED->setScene(graphicsScene);

    waves=new Waves();
    ui->graphicsView->setScene( waves->getScene() );

    dial->setWindowTitle("Ustawienia");

    QGraphicsScene * scene2 = new QGraphicsScene(118,45,100,100);
    QPixmap samochod = QPixmap( "auto.jpg" ) ;
    samochod.scaled(10,10);
    scene2->addPixmap( samochod );
    ui->graphicsView_2->setScene( scene2 );

    ui->graphicsView_LED->setBackgroundBrush(QBrush(QColor(255,0,0)));

    chart = new Chart();
    Chart* chart1= new Chart();
    Chart* chart2= new Chart();
    Chart* chart3= new Chart();
    Chart* chart4= new Chart();
    ui->gridLayout_4->addWidget(chart->getChartView());
    ui->gridLayout_5->addWidget(chart1->getChartView());
    ui->gridLayout_6->addWidget(chart2->getChartView());
    ui->gridLayout_7->addWidget(chart3->getChartView());
    ui->gridLayout_8->addWidget(chart4->getChartView());



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
       chart->addPoint(chart->PointCounter(), czujniki[0]);
       waves->setColour(czujniki);
       ui->lcdNumber_P->display(czujniki[0]);
       ui->lcdNumber_CP->display(czujniki[1]);
       ui->lcdNumber_CL->display(czujniki[2]);
       ui->lcdNumber_L->display(czujniki[3]);
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
