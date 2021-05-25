#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QSerialPortInfo>
#include <QDebug>
#include <QSerialPort>
#include <QStringList>
#include <QLCDNumber>
#include <QGraphicsScene>
#include <QChar>
#include <QtCharts>
#include <QGraphicsEllipseItem>
#include <QTransform>
#include "Settings.h"
#include "Chart.h"
#include "Waves.h"

/*!
*   \file
*   \brief Plik nagłówkowy klasy MainWindow
*/

/*!
    \class MainWindow
    \brief Główne okno aplikacji
*/


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
  void readFromPort();
  void on_pushButton_Settings_clicked();
  void ledOn();
  void ledOff();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *graphicsScene;
    Settings * dial;
    Chart *chart;
    Waves *waves;


};
#endif // MAINWINDOW_H
