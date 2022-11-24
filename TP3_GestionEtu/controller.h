#pragma once
#include <QStringList>
#include <QMessageBox>
#include "promotion.h"

/**
 * @brief AbstractController manage the list of students
*/
class AbstractController
{
public:
    virtual ~AbstractController() {}
    virtual bool control(const QStringList& list) = 0;
};

/**
 * @brief Controller to delete student from the View List
*/
class Controller_DeleteList : public AbstractController
{
private:
    Promotion* promo;
public:
    /**
    * @brief Constructor
    */
    Controller_DeleteList(Promotion* promo) : promo(promo) {}

    /**
    * @brief Control the removing process of students
    * @return Boolean
    */
    virtual bool control(const QStringList& list) override
    {
        // Check the number of parameters
        //if (list.size() != 1) return;
        for (QString student : list)
        {
            promo->remove(student);
        }
        return true;
    }
};

/**
 * @brief ControlLer to add student to the Promotion
*/
class Controller_AddForm : public AbstractController
{
private:
    Promotion* promo;
public:
    /**
    * @brief Constructor
    */
    Controller_AddForm(Promotion* promo) : promo(promo) {}

    /**
    * @brief Control the adding process of a student
    * @return Boolean
    */
    virtual bool control(const QStringList& list) override
    {
        // Check the number of parameters
        if (list.size() != 5) return  false;

        // Check if the ID already exist
        Student studentOld = promo->find(list[0]);
        if (studentOld.getId() != "")
        {
            // Create an error
            QMessageBox::warning(nullptr, "Add Student", "L'étudiant existe déjà.");
            return false;
        }

        // Check the others parameters not NULL
        if (list[0] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "L'ID est vide"); return false;
        }
        if (list[1] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "Le nom de famille est vide"); return false;
        }
        if (list[2] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "Le prenom de famille est vide"); return false;
        }
        if (list[3] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "Le bac est vide"); return false;
        }
        if (list[4] == "")
        {
            QMessageBox::warning(nullptr, "Add Student", "Le département est vide"); return false;
        }

        // Create and add the new student
        Student studentNew(list[0], list[1], list[2], list[3], list[4]);
        promo->add(studentNew);
        QMessageBox::information(nullptr, "Add Student", "L'Etudiant a bien ete insere !");
        return true;
    }
};

/**
 * @brief ControlLer to remove a student
*/
class Controller_DeleteForm : public AbstractController
{
private:
    Promotion* promo;
public:
    /**
    * @brief Constructor
    */
    Controller_DeleteForm(Promotion* promo) : promo(promo) {}

    /**
    * @brief Control the removing process from a student ID
    * @return Boolean
    */
    virtual bool control(const QStringList& list) override
    {
        // Check the number of parameters
        if (list.size() != 1) return false;

        // Search the student
        Student student = promo->find(list[0]);

        // Check if the student has been found
        if (student.getId() != "") {
            promo->remove(student);
            return true;
        }
        return false;
    }
};

/**
 * @brief La Classe Controller_ModifyForm sert de controleur pour modifier les données
*/
class Controller_ModifyForm : public AbstractController
{
private:
    Promotion* promo;
public:
    /**
    * @brief Constructor
    */
    Controller_ModifyForm(Promotion* promo) : promo(promo) {}

    /**
     * @brief Control the modify process from a student ID
     * @return Boolean
     */
    virtual bool control(const QStringList& list) override
    {
        promo->removeSecret(promo->getCurrentModify());

        Student studentNew(list[0], list[1], list[2], list[3], list[4]);
        promo->add(studentNew);
        QMessageBox::information(nullptr, "Modify Student", "L'Etudiant a bien ete modifie !");
        return true;
    }
};
