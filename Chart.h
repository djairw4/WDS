#ifndef CHART_H
#define CHART_H

#include <QtCharts>


/*!
*   \file
*   \brief Plik nagłówkowy klasy Chart
*/

/*!
*   \class Chart
*   \brief Rysowanie wykresu historii pomiarów dla czujnika prawego.
*/

class Chart : public QChart
{
    Q_OBJECT

public:
    Chart(QString title);
    void addPoint(int x, int y);
    QChartView* getChartView();
    QLineSeries* Series();
    int PointCounter();
    void increaseCounter();

private slots:

private:
    QLineSeries *series;
    QChartView *chartView;
    int pointCounter=0;

};

#endif // CHART_H
