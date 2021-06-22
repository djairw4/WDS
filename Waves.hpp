#ifndef WAVES_HPP
#define WAVES_HPP

#include <QGraphicsLineItem>
#include <QGraphicsScene>

/*!
*   \file
*   \brief Plik nagłówkowy klasy Waves
*/

/*!
    \class Waves
    \brief Klasa definiuje obraz samochodu wraz z emitowanymi falami ultradźwiękowymi.
*/

class Waves
{
public:

    /*!
     * \brief Konstruktor klasy.
     *
     * Inicjalizuje obiekt samochodu i fal ultradźwiękowych w kolorze szarym, który utożsamia również brak
     * wykrytych przeszkód
     */
    Waves();

    /*!
     *  \brief Zmiana koloru fal
     *
     *  W zależności od odległości od przeskody koloruje odpowiednio fale wychodzące z czujników,
     *  w miejscu w którym znajduje się przeszkoda. Domyślnie ustawione zakresy:
     *  * kolor SZARY - brak wykrytych przeszkód
     *  * kolor ZIELONY - przeszkoda dalej niż 120 cm
     *  * kolor ŻÓŁTY - przeszkoda dalej niż 60 cm
     *  * kolor POMARAŃCZOWY - przeszkoda dalej niż 30 cm
     *  * kolor CZERWONY - przeszkoda znajduję w odległości nie większej niż 30 cm
     *
     *  \param[in] sensors - tabela z odczytami odległości z czujników, odległość wyrażona w centymetrach
     *  \param[in] ranges - zakresy wartości dla poszczególnych kolorów wynikające z legendy przedstawionej powyżej
     */
    void setColour(int sensors[4],int ranges[3]);

    /*!
     * \brief Metoda zwracająca wyrysowaną scenę
     * \return wskaźnik na pole prywatne <c>scene</c> - obiekt klasy QGraphicsScene
     */
    QGraphicsScene * getScene();
private:
    QGraphicsScene * scene; //!< scena
    QGraphicsLineItem* lines [4][4]; //!< obiekty pokazujące umiejscowienie przeszkody
};

#endif // WAVES_HPP
