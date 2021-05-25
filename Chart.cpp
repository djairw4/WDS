#include "Chart.h"


/*!
*   \file
*   \brief Implementacja metod klasy Chart
*/

/*!
 * \brief Konstruktor klasy.
 *
 *  Tworzy wykres bez danych pomiarowych.
 */

Chart::Chart()
{
    this->series = new QLineSeries();
    this->legend()->hide();
    this->addSeries(series);
    this->createDefaultAxes();
    this->axisY()->setRange(0,200);
    this->axisX()->setRange(series->count()-20,series->count());
    this->axisX()->setTitleText("Czas [s]");
    this->axisY()->setTitleText("Odległość [cm]");
    QFont font;
    font.setPixelSize(18);
    this->setTitleFont(font);
    this->setTitleBrush(QBrush(Qt::black));
    this->setTitle("Czujnik Prawy");

    QPen pen(QRgb(0x0000ff));
    pen.setWidth(2);
    series->setPen(pen);
    chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);
}


/*!
 * \brief Dodaje nowy punkt do wykresu.
 *
 *  Oraz aktualizuje wyświetlany zakres pomiarowy.
 */
void Chart::addPoint(int x, int y)
{
    this->series->append(x, y);
    this->axisX()->setRange(series->count()-20,series->count());
    this->increaseCounter();
}


/*!
 * \brief Zwraca widok wykresu.
 */
QChartView* Chart::getChartView()
{
    return chartView;
}

/*!
 * \brief Zwraca serię danych.
 */
QLineSeries* Chart::Series()
{
    return series;
}

/*!
 * \brief Zwraca aktualną liczbę punktów pomiarowych
 */
int Chart::PointCounter()
{
    return pointCounter;
}

/*!
 * \brief Inkrementuje licznik punktów pomiarowych
 */
void Chart::increaseCounter()
{
    pointCounter++;
}
