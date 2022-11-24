#pragma once
#include <QString>

/**
 * @brief Classe Student
 * @details Cette classe est utiliser pour creer un etudiant en fonction des donnees enregistres.
*/

class Student
{
private:
    QString lastname, firstname, bac, id, departement;
public: 

    Student();
    Student(QString num, QString nom, QString prenom, QString dept, QString fil);

    QString getLastname() { return this->lastname; }
    QString getFirstname() { return this->firstname; }
    QString getBac() { return this->bac; }
    QString getId() { return this->id; }
    QString getDept() { return this->departement; }

    void setId(QString);
    void setPrenom(QString);
    void setNom(QString);
    void setBac(QString);
    void setDept(QString);

};

