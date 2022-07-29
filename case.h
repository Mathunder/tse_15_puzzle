#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "affichage.h"

// Développée par Benjamin Roca
// Cette classe a pour but de définir une case du plateau de jeu. Elle dérive de sf::Text car un texte peut déjà être considéré comme une case
class Case : public sf::Text
{
public:
	// Constructeur sans argument
	Case();
	// Méthode permettant d'échanger une case avec une autre. Plus précisemment, elle permet d'échanger les coordonnées de deux cases : à l'écran, les deux cases sont échangées
	// Argument de type case, puisque c'est avec une case que l'on va échanger la place d'une autre
	// Argument de type sf::RenderWindow et Cadre car ils permettent de trouver la valeur de la largeur de la moitié d'une case du plateau
	// Type void, donc pas de retour
	void exchange(Case &c, sf::RenderWindow& window, Cadre cadre);
};
