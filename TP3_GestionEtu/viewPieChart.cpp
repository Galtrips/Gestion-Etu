#include "viewPieChart.h"

/**
 * @brief Constructeur par default 
*/
ViewPieChart::ViewPieChart()
{
}

/**
 * @brief Constructeur de ViewPieChart
 * @param chart_ : QGroupBox* => La chart
 * @param p : Promotion* => La promotion
*/
ViewPieChart::ViewPieChart(QGroupBox* chart_, Promotion* p) {
	this->chart = chart_;
	this->promo = p;
	this->chartview = nullptr;

	QVBoxLayout* group_box_layout = new QVBoxLayout();
	this->chart->setLayout(group_box_layout);
	this->chart->update();
}

/**
 * @brief Fonction update
 * @details Cette fonction met a jour le diagramme en fonction des departements des etudiants
*/
void ViewPieChart::update() {
	
	QPieSeries* series = new QPieSeries();
	QMap<QString, int> map;

	int nb;
	QString dept;
	this->chart->update();
	for (Student pers : this->promo->getVector()) {

		dept = pers.getDept();

		if (map.contains(dept)) {

			nb = map.value(dept) + 1;
			map.insert(dept, nb);
		}
		else {
			map.insert(dept, 1);
		}
	}

	QMapIterator<QString, int> i(map);
	while (i.hasNext()) {
		i.next();
		series->append(i.key(), i.value());
	}

	series->setLabelsVisible(true);

	QChart* chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Repartition Geographique");
	chart->setTheme(QChart::ChartTheme::ChartThemeBlueCerulean);
	chart->setAnimationOptions(QChart::SeriesAnimations);

	QLayout* layout = this->chart->layout();
	if (this->chartview != nullptr) {
		layout->removeWidget(this->chartview);
	}
	layout->update();

	if (this->chartview != nullptr) {
		delete this->chartview;
	}

	this->chartview = new QChartView(chart);

	layout->addWidget(chartview);

	this->chart->setMaximumSize(QSize(650, 650));
	this->chart->update();
	return;
}