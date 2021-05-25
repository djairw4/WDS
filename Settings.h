#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QMainWindow>
#include <QList>
#include <QSerialPortInfo>
#include <QDebug>
#include <QSerialPort>
#include <QStringList>
#include <QLCDNumber>
#include <QGraphicsScene>
#include <QChar>

/*!
*   \file
*   \brief Plik nagłówkowy klasy Settings
*/


QT_BEGIN_NAMESPACE
namespace Ui { class Settings; }
QT_END_NAMESPACE

/*!
    \class Settings
    \brief Okno ustawień
*/

class Settings : public QDialog
{
   Q_OBJECT

public:
    Settings(QMainWindow *parent = nullptr);
    ~Settings();
    QSerialPort *device;

signals:
    /*!
     *  Sygnał wysyłany w przypadku poprawnego połączenia z portem szeregowym
    */
    void Connection();

    /*!
     *  Sygnał wysyłany w przypadku odłączenia od portu szeregowego.
    */
    void Disconnection();

private slots:
    void on_pushButtonSearch_clicked();
    void ConnectSlot();
    void DisconnectSlot();

private:
    Ui::Settings *ui;

};

#endif // SETTINGS_H
