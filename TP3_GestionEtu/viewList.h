#pragma once
#include <iostream>
#include <QListWidget>

#include "promotion.h"
#include "observer.h"
#include "controller.h"

/**
 * @brief Cette classe permet de gerer la liste d'etudiant sur la partie droite de l'application
*/
class ViewList : public QObject, public Observer
{
	Q_OBJECT
private:
	Promotion* promo;
	QListWidget* list;
	Controller_DeleteList* controller;
public:
	ViewList();
	ViewList(QListWidget* list, Promotion* p);
	void update() override;

public slots:
	void remove();
};

