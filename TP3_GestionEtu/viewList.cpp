#include "viewList.h"

/**
 * @brief ViewList est le constructeur par defaut de ViewList
*/
ViewList::ViewList()
{
}

/**
 * @brief @brief ViewList est un constructeur de ViewList
 * @param list : QListWidget* => La liste
 * @param p : Promotion* => La promotion
*/
ViewList::ViewList(QListWidget* list, Promotion* p)
{
	this->promo = p;
	this->list = list;
	this->controller = new Controller_DeleteList(p);
}

/**
 * @brief Fonction update
 * @details Cette fonction permet la mise a jour de la ViewList de l'application selon si c'est un double click ou une action de modification
*/
void ViewList::update() {
	if (this->promo->getSelectedStudent() != nullptr) {

		QList current = list->selectedItems();
		QStringList students;

		for (QListWidgetItem* i : current) {
			if (i->text() != this->promo->getSelectedStudent()) {
				i->setSelected(false);
			}
		}
		this->promo->setSelected(nullptr);
	}
	else {
		list->clear();
		list->addItems(promo->getList());
	}
}

/**
 * @brief Fonction remove
 * @details Cette fonction permet de supprimer l'etudiant selectionné dans la ViewList
*/
void ViewList::remove() {

	QList current = list->selectedItems();
	QStringList students;

	for (QListWidgetItem* i : current) {
		students.append(i->text());
	}

	this->controller->control(students);
}