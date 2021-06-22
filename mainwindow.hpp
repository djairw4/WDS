#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

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
#include "Settings.hpp"
#include "Chart.hpp"
#include "Waves.hpp"
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

    /*!
     * \brief Konstruktor klasy.
     *
     *  Tworzy główne okno aplikacji
     */
    MainWindow(QWidget *parent = nullptr);

    /*!
     * \brief Destruktor klasy.
     */
    ~MainWindow();


private slots:

    /*!
     * \brief Czytanie z portu szeregowego
     *
     * Odczytuje dane z portu szeregowego, sprawdza czy ramka jest poprawna, jeśli tak to dodaje punkty pomiarowe
     * do wykresów i wyświetla dane z czujników
     */
    void readFromPort();

    /*!
     * \brief Otwieranie okna ustawień.
     */
    void on_pushButton_Settings_clicked();

    /*!
     * \brief Zapalanie diody LED
     *
     * Zapala diodę informującą o statusie połączenia oraz uruchamia odczyt danych.
     */
    void ledOn();

    /*!
     * \brief Gaszenie diody LED
     *
     * Gasi diodę informującą o statusie połączenia,a dokładniej zmienia jej kolor na czerwony
     */
    void ledOff();

    /*!
     * \brief Zmiana wartości dla obiektu <c>spinBox</c> oraz maksymalnego zakresu dla <c>spinBox_2</c>
     * \param[in] val - nowa wartość
     */
    void on_spinBox_valueChanged(int val);

    /*!
     * \brief Zmiana wartości dla obiektu <c>spinBox_2</c> oraz maksymalnego zakresu dla <c>spinBox_3</c>
     * \param[in] val - nowa wartość
     */
    void on_spinBox_2_valueChanged(int val);

    /*!
     * \brief Zmiana wartości dla obiektu <c>spinBox_3</c>
     * \param[in] val - nowa wartość
     */
    void on_spinBox_3_valueChanged(int val);

    /*!
     * \brief Zmiana orientacji samochodu
     * \param[in] value - kąt obrotu w stopniach
     */
    void on_horizontalScrollBar_valueChanged(int value);


private:
    Ui::MainWindow *ui; //!< Interfejs głównego okna
    Settings * dial; //!< Okno ustawień
    Chart * chart[4]; //!< Wykresy historii pomiarów
    Waves *waves; //!< Samochód z falami ultradźwiękowymi
    int ranges[3]; //!< Zakresy do legendy

};
#endif // MAINWINDOW_HPP
