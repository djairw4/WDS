#include "Settings.hpp"
#include "ui_Settings.h"
#include "CRC8.hpp"


/*!
*   \file
*   \brief Implementacja metod klasy Settings
*/



Settings::Settings()
    : ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);
    connect(ui->pushButtonConnect, SIGNAL(clicked()), this, SLOT(ConnectSlot()));
    connect(ui->pushButtonDisconnect, SIGNAL(clicked()), this, SLOT(DisconnectSlot()));

}


Settings::~Settings()
{
    delete ui;
}

QSerialPort *Settings::Device()
{
    return device;
}



void Settings::on_pushButtonSearch_clicked()
{
      ui->comboBoxDevices->clear();
      qDebug()<<"Szukam urządzeń...";
      QList<QSerialPortInfo> devices;
      devices = QSerialPortInfo::availablePorts();

      for(int i = 0; i < devices.count(); i++) {
        qDebug()<<"Znalazłem urządzenie: " + devices.at(i).portName() + " " + devices.at(i).description();
        ui->comboBoxDevices->addItem(devices.at(i).portName() + "\t" + devices.at(i).description());
      }
}



void Settings::ConnectSlot()
{
    if(ui->comboBoxDevices->count() == 0) {
      qDebug()<<"Nie wykryto żadnych urządzeń!";
    }

    QString portName = ui->comboBoxDevices->currentText().split("\t").first();
    this->device->setPortName(portName);

    // OTWÓRZ I SKONFIGURUJ PORT:
    if(!device->isOpen()) {
    if(device->open(QSerialPort::ReadWrite)) {
      this->device->setBaudRate(QSerialPort::Baud115200);
      this->device->setDataBits(QSerialPort::Data8);
      this->device->setParity(QSerialPort::NoParity);
      this->device->setStopBits(QSerialPort::OneStop);
      this->device->setFlowControl(QSerialPort::NoFlowControl);

     // CONNECT:
     qDebug()<<"Otwarto port szeregowy.";
     emit Connection();

    } else {
      qDebug()<<"Otwarcie portu szeregowego się nie powiodło!";
    }
    }
    else{
        qDebug()<<"Port już jest otwarty!";
    }
}




void Settings::DisconnectSlot()
{
    if(this->device->isOpen()) {
      this->device->close();
      qDebug()<<"Zamknięto połączenie.";
      emit Disconnection();

    } else {
      qDebug()<<"Port nie jest otwarty!";
    }
}

