#include "TP3_GestionEtu.h"
#include "promotion.h"
#include <QApplication>

/**
 * @brief Corps de l'application
 * @details Le main lance et initialise l'application avec les donnees datas.
 * @param argc : Un argument
 * @param argv : L'argument
 * @return Integer
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Promotion
    Promotion* promo = new Promotion();
    promo->loadFileCSV("promoDUT.csv");

    // Create Interface
    TP3_GestionEtu w;
    w.setData(promo);
    w.show();

    return a.exec();
}
