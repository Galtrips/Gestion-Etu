#include "student.h"
#include <QString>

/**
* @brief Constructeur par default de Student
* @details Ce constructeur ne prend aucun parametre.
*/

Student::Student() {

}

/**
* @brief Constructeur de Student
* @details Prend en parametre les diffarentes caracteristiques  d'un etudiant afin de creer un objet Student.
*/

Student::Student(QString num, QString nom, QString prenom, QString dept, QString fil)
{
	this->id = num;
	this->lastname = nom;
	this->firstname = prenom;
	this->departement = dept;
	this->bac = fil;
}

/**
 * @brief Setter de l'ID
 * @param num : QString => Le numero etudiant
*/
void Student::setId(QString num) {
	this->id = num;
}

/**
 * @brief Setter du prenom
 * @param prenom : QString => Le prenom
*/
void Student::setPrenom(QString prenom) {
	this->firstname = prenom;
}

/**
 * @brief Setter du nom
 * @param nom : QString => Le nom
*/
void Student::setNom(QString nom) {
	this->lastname = nom;
}

/**
 * @brief Setter du bac
 * @param bac : QString => Le bac
*/
void Student::setBac(QString bac) {
	this->bac = bac;
}

/**
 * @brief Setter du departement
 * @param dept : QString => Le departement
*/
void Student::setDept(QString dept) {
	this->departement = dept;
}
