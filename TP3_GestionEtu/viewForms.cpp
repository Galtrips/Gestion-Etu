#include "viewForms.h"

/**
 * @brief ViewForms est le constructeur par defaut de ViewForms
*/
ViewForms::ViewForms() 
{
}

/**
 * @brief ViewForms est un constructeur qui permet de creer les diffrents pushButtons, lineEdits et label de la Box_addStudent
 * @param addNum : QLineEdit* => Un input
 * @param addPrenom : QLineEdit* => Un input
 * @param addNom : QLineEdit* => Un input
 * @param addBac : QComboBox* => Une box
 * @param addDept : QComboBox* => Une box
 * @param delNum : QLineEdit* => Un input
 * @param p : Promotion* => Une promotion
*/
ViewForms::ViewForms(QLineEdit* addNum, QLineEdit* addPrenom, QLineEdit* addNom, QComboBox* addBac, QComboBox* addDept, QLineEdit* delNum, QPushButton* ajout, QPushButton* modifier, QPushButton* reset, Promotion* p) {
	this->addNum = addNum;
	this->addPrenom = addPrenom;
	this->addNom = addNom;
	this->addBac = addBac;
	this->addDept = addDept;

	this->ajout = ajout;
	this->modifier = modifier;
	this->reset = reset;

	this->delNum = delNum;
	this->promo = p;

	this->addForm = new Controller_AddForm(p);
	this->delForm = new Controller_DeleteForm(p);
	this->editForm = new Controller_ModifyForm(p);

	this->initialisation();
}

/**
 * @brief initialisation permet d'initialiser les proprietes de la Box_addStudent 
 * @return Boolean
*/
bool ViewForms::initialisation() {
	try {
	
		for (int i = 1; i <= 95; i++) {
			this->addDept->addItem(QString::number(i));
		}
		this->addDept->addItem("Autre");

		this->addBac->addItem("S");
		this->addBac->addItem("ES");
		this->addBac->addItem("L");
		this->addBac->addItem("Pro");
		this->addBac->addItem("STI2D");
		this->addBac->addItem("Nouveau Bac");
		this->addBac->addItem("Segpa");

		this->modifier->hide();
		this->reset->hide();

		return true;
	}
	catch (const std::exception& e) {
		qDebug() << e.what();
		return false;
	}
}

/**
 * @brief add permet de creer un nouveau Student uniquement si les veleurs entrees passent correctement le contrôle
 * @return Boolean
*/
bool ViewForms::add() {
	try {

		QStringList list;

		list.append(this->addNum->text());
		list.append(this->addNom->text());
		list.append(this->addPrenom->text());
		list.append(this->addDept->currentText());
		list.append(this->addBac->currentText());

		bool test = this->addForm->control(list);

		if (test == true) {
			this->addNum->setText("");
			this->addPrenom->setText("");
			this->addNom->setText("");
		}	

		return true;

	} catch (const std::exception& e) {
		qDebug() << e.what();
		return false;
	}
}

/**
 * @brief remove permet de suprimer un Student uniquement si le numero entree existe
 * @return Boolean
*/
bool ViewForms::remove() {
	try {

		QStringList list;

		list.append(this->delNum->text());
		
		bool test = this->delForm->control(list);

		if (test == true) {
			this->delNum->setText("");
		}

		return true;

	}
	catch (const std::exception& e) {
		qDebug() << e.what();
		return false;
	}
}

/**
 * @brief Fonction update
 * @details Cette fonction permet de mettre a jour les donnees presentes dans les forms de l'application
*/
void ViewForms::update() {
	this->ajout->setVisible(true);
	this->modifier->hide();
	this->reset->hide();
	this->addNum->setText("");
	this->addNom->setText("");
	this->addPrenom->setText("");
	this->promo->setSelected(nullptr);
}

/**
 * @brief Fonction Modify
 * @details Cette fonction permet de modifier les donnees apres un evenement de double click sur la ViewList
 * @param item : QListWidgetItem* => L'item a return
*/
void ViewForms::modify(QListWidgetItem* item) {
	this->promo->setSelected(item->text());
	promo->notifyObserver();

	this->ajout->hide();
	this->modifier->setVisible(true);
	this->reset->setVisible(true);

	QStringList list;
	list = item->text().split(QRegularExpression("\\W+"));
	Student student = this->promo->find(list[0]);
	this->promo->setCurrentModify(student);
	
	this->addNum->setText(student.getId());
	this->addNom->setText(student.getLastname());
	this->addPrenom->setText(student.getFirstname());
	this->addBac->setCurrentText(student.getBac());
	this->addDept->setCurrentText(student.getDept());
}

/**
 * @brief Fonction resetButton
 * @details Permet de lancer une update et de remettre a vide et le form
*/
void ViewForms::resetButton() {
	this->update();
}

/**
 * @brief Fonction modifyStudent
 * @details Permet la modification direct d'un etudiant et envoies les informations au controller.
*/
void ViewForms::modifyStudent() {

	QStringList list;

	list.append(this->addNum->text());
	list.append(this->addNom->text());
	list.append(this->addPrenom->text());
	list.append(this->addDept->currentText());
	list.append(this->addBac->currentText());

	this->editForm->control(list);

	this->addNum->setText("");
	this->addPrenom->setText("");
	this->addNom->setText("");
}