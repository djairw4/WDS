#ifndef CHART_HPP
#define CHART_HPP

#include <QtCharts>


/*!
*   \file
*   \brief Plik nagłówkowy klasy Chart
*
*/

/*!
*   \class Chart
*   \brief Rysowanie wykresu historii pomiarów dla czujnika odległości
*/

class Chart : public QChart
{
    Q_OBJECT

public:

    /*!
     * \brief Konstruktor klasy.
     * \param[in] title - tytuł wykresu, obiekt klasy QString
     *
     *  Tworzy wykres bez danych pomiarowych. Wykres zawiera określone dla czujnika ogległości, nazwane osie
     *  (Y - odległość [cm], X - moment czasu od początku przesyłu danych [s] ), podany w parametrze tytuł wykresu,
     *  zakres pomiarowy na osi X ustawiony na 20 ostatnich pomiarów oraz domyślny zakres wartości między 0 a 200cm.
     */
    Chart(QString title);

    /*!
     *  \brief Dodaje nowy punkt do wykresu, aktualizuje wyświetlany zakres pomiarowy i licznik pomiarów.
     *  \param[in] x - współrzędna x nowego punktu
     *  \param[in] y - współrzędna y nowego punktu
     */
    void addPoint(int x, int y);

    /*!
     * \brief Zwraca widok wykresu.
     * \return wskaźnik na pole prywatne <c>chartView</c> typu QChartView
     */
    QChartView* getChartView();

    /*!
     * \brief Zwraca serię danych wykresu.
     * \return wskaźnik na pole prywatne <c>series</c> typu QLineSeries
     */
    QLineSeries* Series();

    /*!
     * \brief Zwraca aktualną liczbę punktów pomiarowych
     * \return pole prywatne <c>pointCounter</c> definiujące licznik punktów pomiarowych
     */
    int PointCounter();

    /*!
     * \brief Inkrementuje licznik punktów pomiarowych
     */
    void increaseCounter();

private:

    QLineSeries *series; //!< Seria danych pomiarowych
    QChartView *chartView; //!< Widok wykresu
    int pointCounter=0; //!< Licznik punktów pomiarowych

};

#endif // CHART_HPP
