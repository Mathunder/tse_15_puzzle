#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

// Classe d�velopp�e par Matthieu d'Hoop
// La classe Cadre a pour but de simplifier la cr�ation d'un plateau de jeu (cadre + grille).

class Cadre
{
	int largeur_;
	std::vector<sf::RectangleShape> lines_cadre_;
	std::vector<sf::RectangleShape> lines_grid_;
	std::vector<sf::RectangleShape> lines_menu_;
public:
	// Constructeur prenant comme param�tre la largeur du carr� formant le bord de la grille de jeu
	Cadre(int largeur);
	// Constructeur sans param�tre 
	Cadre();
	// Destructeur de la classe
	~Cadre();
	// M�thode en ligne de type get permettant de r�cup�rer la largeur du cadre
	// Pas d'argument
	// Retourne un entier
	int getLargeur() const { return largeur_; }
	// M�thode de type get permettant de r�cup�rer les lignes d�finissant le cadre de jeu
	// Pas d'argument
	// Retourne un vecteur contenant des types RectangleShape
	std::vector<sf::RectangleShape> getLines_cadre()  { return lines_cadre_; }
	// M�thode de type get permettant de r�cup�rer les lignes d�finissant la grille de jeu
	// Pas d'argument
	// Retourne un vecteur contenant des types RectangleShape
	std::vector<sf::RectangleShape> getLines_grid() { return lines_grid_; }
	// M�thode de type get permettant de r�cup�rer les lignes s�parant les diff�rentes boutons du menu secondaire affich� durant la partie
	// Pas d'argument
	// Retourne un vecteur contenant des types RectangleShape
	std::vector<sf::RectangleShape> getLines_menu() { return lines_menu_; }
	// M�thode de type set permettant de d�finir la largeur/longueur du cadre
	// Argument de type entier pour initialiser la largeur
	// Type void, donc pas de retour
	void setLargeur(int largeur);
	// M�thode de type set permettant de d�finir lignes d�finissant le cadre de jeu
	// Argument i de type entier, servant de compteur de boucle
	// Arguments pos_x et pos_y de type float afin d'initialiser la position de la ligne
	// Argument de type sf::Color afin d'initialiser la couleur de la ligne
	// Arguments hauteur et largeur de type entiers afin de d�terminer la longeur et l'�paisseur des lignes
	// Type void, donc pas de retour
	void setLines_cadre(int i, float pos_x, float pos_y, sf::Color color, int largeur, int hauteur);
	// M�thode de type set permettant de d�finir les lignes d�finissant la grille de jeu
	// Pour les arguments : m�me chose que pour la m�thode pr�c�dente
	// Type void, donc pas de retour
	void setLines_grid(int i, float pos_x, float pos_y, sf::Color color, int largeur, int hauteur);
	// M�thode de type set permettant de d�finir les lignes s�parant les diff�rentes boutons du menu secondaire affich� durant la partie
	// Pour les arguments : m�me chose que pour la m�thode pr�c�dente
	// Type void, donc pas de retour
	void setLines_menu(int i, float pos_x, float pos_y, sf::Color color, int largeur, int hauteur);
};

