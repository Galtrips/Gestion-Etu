#include "promotion.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QRegularExpression>

/**
 * @brief Constructeur par default de Promotion
 * @details Ne prend aucun parametre
*/
Promotion::Promotion()
{
    this->selectedStudent = nullptr;
}

/**
  * @brief Fonction loadFileCSV
  * @details Prend un fichier en parametre
  * Cette fonction sert a recuperer les donnees sur les etudiants enregistres dans le fichier Data de la racine du projet.
  * La fonction retourne le succes ou non de la fonction
  * @param nomFichier : QString => Le nom du fichier
  * @return Boolean
*/
bool Promotion::loadFileCSV(QString nomFichier) {
    QFile fichier(QDir::currentPath() + "/../data/" + nomFichier);
    try {
        if (fichier.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream flux(&fichier);

            QString line;

            QString num;
            QString nom;
            QString prenom;
            QString dept;
            QString bac;

            while (!flux.atEnd())
            {

                line = flux.readLine();
                QStringList list;
                list = line.split(QRegularExpression(";"));

                num = list[0];
                nom = list[1];
                prenom = list[2];
                dept = list[3];
                bac = list[4];


                studentList.append(Student(num, nom, prenom, dept, bac));
            }
            fichier.close();
            return true;
        }
    }
    catch (const std::exception& e) {
        return false;
    }
}

/**
 * @brief Fonction print
 * @details Ne prend aucun parametre
 * La fonction print permet d'afficher dans la console l'ensemble des donnees recuperer dans une promotions
*/
void Promotion::print() {
    for (auto pers : studentList) {
        qDebug() << pers.getId() << " " << pers.getLastname() << " " << pers.getFirstname() << " " << pers.getDept() << " " << pers.getBac();
    }
}

/**
 * @brief Fonction getList
 * @details Ne prend aucun parametre
 * Retourne La liste d'etudiant actuel de l'application au format texte
 * @return QStringList
 */
QStringList Promotion::getList() {
    QStringList students;
    QString infos;

    for (auto student : this->studentList) {
        infos = student.getId() + " - " + student.getLastname() + " " + student.getFirstname() + " ("+ student.getDept() + ")";
        students.append(infos);
    }
    return students;
};

/**
 * @brief Fonction getSelectedStudent
 * @details Ne prend aucun parametre
 * Retourne l'etudiant selectionne
 * @return QString
 */
QString Promotion::getSelectedStudent() {
    return this->selectedStudent;
}

/**
 * @brief Fonction setSelected
 * @details Elle permet de definir l'etudiant selectionne dans la ViewList
 * @param student : QString => L'etudiant selectionne
*/
void Promotion::setSelected(QString student) {
    this->selectedStudent = student;
};

/**
* @brief Fonction addObserver
* @details Cette fonction permet d'ajouter un observer a la classe pour actualiser les vues
* @param view : Observer* => L'observer a ajouter
*/
void Promotion::addObserver(Observer* view) {
    this->views.append(view);
}

/**
* @brief Fonction removeObserver
* @details Cette fonction  permet de retier un observer a la classe pour enlever l'actualisation
 * @param view : Observer* => L'observer a retirer
*/
void Promotion::removeObserver(Observer* view) {
    int cpt = 0;
    for (auto observer : this->views) {
        if (observer == view) {
            this->views.remove(cpt);
            break;
        }
        cpt++;
    }
}

/**
* @brief Fonction notifyObserver
* @details Cette fonction permet de mettre à jour l'ensemble des donnees des classes
*/
void Promotion::notifyObserver() {
    for (auto observer : this->views) {
        observer->update();
    }
}

/**
 * @brief Fonction add
 * @details Cette fonction ajoute un eleve à la promotion
 * @param s : Student => L'etudiant a ajouter
 * @return Student
 */
Student Promotion::add(Student s) {
    this->studentList.append(s);
    notifyObserver();
    return s;
}

/**
 * @brief Fonction remove
 * @details Cette fonction supprime un eleve de la promotion
 * @param s : Student => L'etudiant a retirer
 * @return QString
*/
QString Promotion::remove(QString s) {
    QStringList list;
    list = s.split(QRegularExpression("\\W+"));
    int cpt = 0;

    for (Student student : this->studentList) {
        if (list[0] == student.getId()) {
            this->studentList.remove(cpt);
            notifyObserver();
            return s;
        }
        cpt++;
    }
}

/**
 * @brief Fonction remove
 * @details Cette fonction supprime un eleve de la promotion
 * @param s : Student => L'etudiant a supprimer
 * @return Student
*/
Student Promotion::remove(Student s) {
    int cpt = 0;
    for (Student student : this->studentList) {
        if (s.getId() == student.getId()) {
            this->studentList.remove(cpt);
            notifyObserver();
            return s;
        }
        cpt++;
    }
}

/**
* @brief Fonction removeSecret
* @details Cette fonction supprime un eleve de la promotion Sans update les donnees
* @param s : Student => L'etudiant a ajouter
* @return Student
*/
Student Promotion::removeSecret(Student s) {
    int cpt = 0;
    for (Student student : this->studentList) {
        if (s.getId() == student.getId()) {
            this->studentList.remove(cpt);
            notifyObserver();
            return s;
        }
        cpt++;
    }
}

/**
 * @brief Fonction find
 * @details Cette fonction trouve un etudiant dans la promotion actuelle
 * @param id : QString => L'id de l'etudiant a trouver
 * @return
*/
Student Promotion::find(QString id) {
    int cpt = 0;
    for (Student student : this->studentList) {
        if (id == student.getId()) {
            return student;
        }
        cpt++;
    }
    return Student("", "", "", "", "");
}
