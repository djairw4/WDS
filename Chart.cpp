#include "Chart.hpp"


/*!
*   \file
*   \brief Implementacja metod klasy Chart
*/


Chart::Chart(QString title)
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
    this->setTitle(title);

    QPen pen(QRgb(0x0000ff));
    pen.setWidth(2);
    series->setPen(pen);
    chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);
}



void Chart::addPoint(int x, int y)
{
    this->series->append(x, y);
    this->axisX()->setRange(series->count()-20,series->count());
    this->increaseCounter();
}


QChartView* Chart::getChartView()
{
    return chartView;
}


QLineSeries* Chart::Series()
{
    return series;
}


int Chart::PointCounter()
{
    return pointCounter;
}


void Chart::increaseCounter()
{
    pointCounter++;
}
