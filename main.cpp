#include "mainwindow.hpp"
#include "Settings.hpp"

#include <QApplication>


/*!
*   \file
*   \brief Główny plik programu
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
