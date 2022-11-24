#pragma once

#include <QMainWindow>
#include "ui_TP3_GestionEtu.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewPieChart.h"
#include "viewHistogram.h"
#include "Promotion.h"

/**
 * @brief TP3_GestionEtu creer la fenetre principale
*/

class TP3_GestionEtu : public QMainWindow
{
    Q_OBJECT

public:
    TP3_GestionEtu(QWidget *parent = nullptr);
    ~TP3_GestionEtu() {}

    void setData(Promotion* p);

private:
    Ui::TP3_GestionEtuClass ui;
    ViewList* listView;
    ViewForms* listForm;
    ViewPieChart* pieChartView;
    ViewHistogram* histogramView;
    Promotion* promo;
    
};
