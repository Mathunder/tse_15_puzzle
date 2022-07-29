#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "affichage.h"

// D�velopp�e par Benjamin Roca
// Cette classe a pour but de d�finir une case du plateau de jeu. Elle d�rive de sf::Text car un texte peut d�j� �tre consid�r� comme une case
class Case : public sf::Text
{
public:
	// Constructeur sans argument
	Case();
	// M�thode permettant d'�changer une case avec une autre. Plus pr�cisemment, elle permet d'�changer les coordonn�es de deux cases : � l'�cran, les deux cases sont �chang�es
	// Argument de type case, puisque c'est avec une case que l'on va �changer la place d'une autre
	// Argument de type sf::RenderWindow et Cadre car ils permettent de trouver la valeur de la largeur de la moiti� d'une case du plateau
	// Type void, donc pas de retour
	void exchange(Case &c, sf::RenderWindow& window, Cadre cadre);
};
