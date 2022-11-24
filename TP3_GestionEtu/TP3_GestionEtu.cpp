#include "TP3_GestionEtu.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewPieChart.h"

/**
 * @brief TP3_GestionEtu creer la fenetre principale
 * @param parent : QWidget* => La fenetre
*/

TP3_GestionEtu::TP3_GestionEtu(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

/**
 * @brief setData vas initialiser/implementer toutes les datas : les views et leurs contenus, les observeurs ainsi que les boutons
 * @param p : Promotion* => La promotion
*/

void TP3_GestionEtu::setData(Promotion* p) {

    promo = p;
    this->listView = new ViewList(ui.listWidget, this->promo);
    this->listForm = new ViewForms(ui.lineEdit_add_number, ui.lineEdit_add_firstname, ui.lineEdit_add_lastname, ui.lineEdit_add_BAC, ui.lineEdit_add_department, ui.lineEdit_remove_number, ui.pushButton_addStudent, ui.pushButton_modifyStudent, ui.pushButton_reset, this->promo);
    this->pieChartView = new ViewPieChart(ui.groupBox_department, this->promo);
    this->histogramView = new ViewHistogram(ui.groupBox_bacs, this->promo);

    p->addObserver(listView);
    p->addObserver(pieChartView);
    p->addObserver(histogramView);
    p->addObserver(listForm);

    p->notifyObserver();

    connect(ui.pushButton_delete_list, &QPushButton::pressed, listView, &ViewList::remove);
    connect(ui.listWidget, &QListWidget::itemDoubleClicked, listForm, &ViewForms::modify);

    connect(ui.pushButton_addStudent, &QPushButton::pressed, listForm, &ViewForms::add);
    connect(ui.pushButton_delete_number, &QPushButton::pressed, listForm, &ViewForms::remove);
    connect(ui.pushButton_reset, &QPushButton::pressed, listForm, &ViewForms::resetButton);
    connect(ui.pushButton_modifyStudent, &QPushButton::pressed, listForm, &ViewForms::modifyStudent);
}
