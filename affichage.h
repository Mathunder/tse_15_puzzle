#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

// Classe développée par Matthieu d'Hoop
// La classe Cadre a pour but de simplifier la création d'un plateau de jeu (cadre + grille).

class Cadre
{
	int largeur_;
	std::vector<sf::RectangleShape> lines_cadre_;
	std::vector<sf::RectangleShape> lines_grid_;
	std::vector<sf::RectangleShape> lines_menu_;
public:
	// Constructeur prenant comme paramètre la largeur du carré formant le bord de la grille de jeu
	Cadre(int largeur);
	// Constructeur sans paramètre 
	Cadre();
	// Destructeur de la classe
	~Cadre();
	// Méthode en ligne de type get permettant de récupérer la largeur du cadre
	// Pas d'argument
	// Retourne un entier
	int getLargeur() const { return largeur_; }
	// Méthode de type get permettant de récupérer les lignes définissant le cadre de jeu
	// Pas d'argument
	// Retourne un vecteur contenant des types RectangleShape
	std::vector<sf::RectangleShape> getLines_cadre()  { return lines_cadre_; }
	// Méthode de type get permettant de récupérer les lignes définissant la grille de jeu
	// Pas d'argument
	// Retourne un vecteur contenant des types RectangleShape
	std::vector<sf::RectangleShape> getLines_grid() { return lines_grid_; }
	// Méthode de type get permettant de récupérer les lignes séparant les différentes boutons du menu secondaire affiché durant la partie
	// Pas d'argument
	// Retourne un vecteur contenant des types RectangleShape
	std::vector<sf::RectangleShape> getLines_menu() { return lines_menu_; }
	// Méthode de type set permettant de définir la largeur/longueur du cadre
	// Argument de type entier pour initialiser la largeur
	// Type void, donc pas de retour
	void setLargeur(int largeur);
	// Méthode de type set permettant de définir lignes définissant le cadre de jeu
	// Argument i de type entier, servant de compteur de boucle
	// Arguments pos_x et pos_y de type float afin d'initialiser la position de la ligne
	// Argument de type sf::Color afin d'initialiser la couleur de la ligne
	// Arguments hauteur et largeur de type entiers afin de déterminer la longeur et l'épaisseur des lignes
	// Type void, donc pas de retour
	void setLines_cadre(int i, float pos_x, float pos_y, sf::Color color, int largeur, int hauteur);
	// Méthode de type set permettant de définir les lignes définissant la grille de jeu
	// Pour les arguments : même chose que pour la méthode précédente
	// Type void, donc pas de retour
	void setLines_grid(int i, float pos_x, float pos_y, sf::Color color, int largeur, int hauteur);
	// Méthode de type set permettant de définir les lignes séparant les différentes boutons du menu secondaire affiché durant la partie
	// Pour les arguments : même chose que pour la méthode précédente
	// Type void, donc pas de retour
	void setLines_menu(int i, float pos_x, float pos_y, sf::Color color, int largeur, int hauteur);
};

