#include "viewHistogram.h"

/**
 * @brief Constructeur par defaut
*/
ViewHistogram::ViewHistogram() 
{
}

/**
 * @brief Constructeur de ViewHistogram
 * @param chart : QGroupBox* => La groupBox
 * @param p : Promotion* => La promotion
*/
ViewHistogram::ViewHistogram(QGroupBox* chart_, Promotion* p) {
	this->chart = chart_;
	this->promo = p;
	this->chartview = nullptr;

	QVBoxLayout* group_box_layout = new QVBoxLayout();
	this->chart->setLayout(group_box_layout);
	this->chart->update();
}

/**
 * @brief Fonction update
 * @details Cette fonction permet la mise a jour du graphique en cas d'evenement sur les etudiants
*/
void ViewHistogram::update() {

	QBarSeries* series = new QBarSeries();
	QMap<QString, int> map;

	int nb;
	QString bac;
	this->chart->update();
	for (Student pers : this->promo->getVector()) {

		bac = pers.getBac();

		if (map.contains(bac)) {

			nb = map.value(bac) + 1;
			map.insert(bac, nb);
		}
		else {
			map.insert(bac, 1);
		}
	}

	QVector<QBarSet*> sets;
	QMapIterator<QString, int> i(map);
	while (i.hasNext()) {
		i.next();

		QBarSet* tempo = new QBarSet(i.key());
		*tempo << i.value();
		sets.push_back(tempo);
	}

	for (QBarSet* value : sets)
	{
		series->append(value);
	}

	series->setLabelsVisible(true);

	QChart* chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Series de bac");
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
	this->chartview->resize(200, 200);

	layout->addWidget(chartview);

	this->chart->setMaximumSize(QSize(650, 650));
	this->chart->update();

	return;
}