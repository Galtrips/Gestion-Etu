#pragma once

/**
 * @brief Classe Observer
 * @details Cette classe est utilise pour mettre a jour les vues de l'application
 * Elle est sous le Design Patern Observer
*/
class Observer {
public:

  /**
   * @brief Destructeur par default de la classe
  */
  virtual ~Observer() {}

  /**
   * @brief Fonction update
   * @details  Cette fonction est la fonction qui sera utilise pour update les donnees des vues
   * C'est une fonction virtuelle a redefinir a l'heritage de la classe Observer
  */
  virtual void update() = 0;
};

/**
 * @brief Classe Observable
 * @details Cette classe est utilise pour mettre a jour les donnees de l'application
 * Elle est sous le Design Patern Observer
*/
class Observable {
public:

  /**
  * @brief Destructeur par default de la classe
  */
  virtual ~Observable() {}

  /**
   * @brief Fonction addObserver
   * @details Cette fonction permet d'ajouter un Observer a la series de donnees. Cela permet a la serie de donnees d'envoyer ses nouvelles informations aux observers.
   * @param observer 
  */
  virtual void addObserver(Observer* observer) = 0;

  /**
   * @brief Fonction removeObserver
   * @details Cette fonction permet de retirer un Observer a la series de donnees. Cela permet a la serie de donnees de ne plus envoyer ses nouvelles informations aux observers.
   * @param observer
  */
  virtual void removeObserver(Observer* observer) = 0;

  /**
   * @brief Fonction notifyObserver
   * @details Cette fonction permet de mettre a jour l'ensemble des observer ajoute a la donnees. Elle met donc a jour les vues.
  */
  virtual void notifyObserver() = 0;
};
