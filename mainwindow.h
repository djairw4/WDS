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
#include <QSpinBox>



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

  void on_spinBox_valueChanged(int arg1);

  void on_spinBox_2_valueChanged(int arg1);

  void on_spinBox_3_valueChanged(int arg1);

  void on_horizontalScrollBar_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *graphicsScene;
    Settings * dial;
    Chart * chart[4];
    Waves *waves;
    int zakresy[3];
    int rotacja;

signals:
  void valueChanged(int i);

};
#endif // MAINWINDOW_H
