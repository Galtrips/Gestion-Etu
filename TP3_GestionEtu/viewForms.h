#pragma once
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QListWidgetItem>

#include "promotion.h"
#include "controller.h"
#include "observer.h"

/**
 * @brief Cette classe ViewForms permet d'avoir l'ensemble des donnees sur les formulaires et les fonctions a executer
*/
class ViewForms : public QObject, public Observer
{
	Q_OBJECT
private:
	Promotion* promo;
	
	QLineEdit* addNum;
	QLineEdit* addPrenom;
	QLineEdit* addNom;
	QComboBox* addBac;
	QComboBox* addDept;

	QPushButton* ajout;
	QPushButton* modifier;
	QPushButton* reset;

	QLineEdit* delNum;

	Controller_AddForm* addForm;
	Controller_DeleteForm* delForm;
	Controller_ModifyForm* editForm;

	bool initialisation();
public:
	ViewForms();
	ViewForms(QLineEdit* addNum, QLineEdit* addPrenom, QLineEdit* addNom, QComboBox* addBac, QComboBox* addDept, QLineEdit* delNum, QPushButton* ajout, QPushButton* modifier, QPushButton* reset, Promotion* p);
	void update() override;

public slots:
	bool add();
	bool remove();
	void modify(QListWidgetItem* item);
	void resetButton();
	void modifyStudent();
};

