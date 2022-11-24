#pragma once
#include "promotion.h"
#include <QGroupBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QMap>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>


/**
 * @brief Cette classe permet la gestion du diagramme modelisant l'ensemble des departements des etudiants
*/
class ViewPieChart : public QObject, public Observer
{
	Q_OBJECT
private:
	QGroupBox* chart;
	Promotion* promo;
	QChartView* chartview;

public:
	ViewPieChart();
	ViewPieChart(QGroupBox* chart, Promotion* p);
	void update() override;
};

