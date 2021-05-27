#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QDialog>
#include <QList>
#include <QSerialPortInfo>
#include <QDebug>
#include <QSerialPort>

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

    /*!
     * \brief Konstruktor klasy.
     *
     *  Tworzy okienko z ustawieniami komunikacji z portem szeregowym
     */
    Settings();

    /*!
     * \brief Destruktor klasy.
     */
    ~Settings();

    /*!
     * \brief Zwraca wskaźnik do urządzenia, z którym komunikuje się aplikacja
     * \return wskaźnik na pole prywatne <c>device</c> - obiekt QSerialPort
     */
    QSerialPort * Device();


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

    /*!
     * \brief Slot szukania dostępnych portów
     *
     *  Nazwy znalezionych portów wyświetla w obiekcie comboBoxDevices
     */
    void on_pushButtonSearch_clicked();

    /*!
     * \brief Slot połączenia z wybranym portem szeregowym
     *
     *  Łączy z portem i ustawia parametry transmisji( Szybkość transmisji:115200, 8 bitów danych,
     *  brak bitu parzystości, 1 bit stopu i brak kontroli przepływu) oraz emitucje sygnał Connection()
     */
    void ConnectSlot();

    /*!
     * \brief Slot zakończenia połączenia z portem szeregowym
     *
     *  Jeśli port szeregowy jest otawrty odłącza się od niego oraz emituje sygnał Disconnection().
     */
    void DisconnectSlot();

private:
    Ui::Settings *ui; //!< Interfejs okna ustawień
    QSerialPort *device; //!< Urządzenie z którym komunikuje się aplikacja

};

#endif // SETTINGS_HPP
