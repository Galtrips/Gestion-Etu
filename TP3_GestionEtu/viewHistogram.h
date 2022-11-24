#pragma once
#include "promotion.h"
#include <QGroupBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QMap>
#include <QVector>

#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

/**
 * @brief Cette classe ViewHistogram permet la gestion de la chart Histogram representant les bacs des etudiants
*/
class ViewHistogram : public QObject, public Observer
{
	Q_OBJECT
private:
	QGroupBox* chart;
	Promotion* promo;
	QChartView* chartview;
public:
	ViewHistogram();
	ViewHistogram(QGroupBox* chart, Promotion* p);
	void update() override;
};

