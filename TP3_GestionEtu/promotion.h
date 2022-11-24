#pragma once
#include <QString>
#include <QVector>
#include <QStringList>

#include "student.h"
#include "observer.h"

/**
* @brief Classe Promotion
* @details Cette classe est utilisee pour stocker les differents etudiants enregistres dans une promotion
*/

class Promotion : public Observable
{
private:
	QVector<Student> studentList;
	QString selectedStudent;
	QVector<Observer*> views;
	Student currentModify;
public:

	Promotion();
	bool loadFileCSV(QString fichier);
	void print();
	QStringList getList();
	QString getSelectedStudent();
	void setSelected(QString);

	Student add(Student s);
	QString remove(QString s);
	Student remove(Student s);
	Student removeSecret(Student s);
	Student find(QString id);

	void addObserver(Observer* view) override;
	void removeObserver(Observer* view) override;
	void notifyObserver() override;

	/**
	 * @brief Fonction getVector
	 * @details Cette fonction permet de retourner la liste d'etudiant enregistre dans la classe promotion.
	 * @return QVector<Student> : Un tableau d'etudiants
	*/
	QVector<Student> getVector() { return this->studentList; }

	/**
	 * @brief Fonction getCurrentModify
	 * @details Retourne l'objet etudiant qui est en cours de modification.
	 * @return Student : Un etudiant
	*/
	Student getCurrentModify() { return this->currentModify; }

	/**
	 * @brief Fonction setCurrentModify
	 * @details Permet de definir l'ettudiant qui est actuellement selectionne pour le modifier
	 * @param Student : Un etudiant
	*/
	void setCurrentModify(Student s) { this->currentModify = s; }
};

