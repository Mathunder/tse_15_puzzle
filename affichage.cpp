#include "affichage.h"

Cadre::Cadre(int largeur)
{
	largeur_ = largeur;
}

Cadre::Cadre()
{
	largeur_ = 700;
}

Cadre::~Cadre() {}

 void Cadre::setLargeur(int largeur)
 {
	 largeur_ = largeur;
 }

 void Cadre::setLines_cadre(int i, float pos_x, float pos_y, sf::Color color, int largeur, int hauteur)
 {
	 lines_cadre_.push_back(sf::RectangleShape(sf::Vector2f(largeur, hauteur)));
	 lines_cadre_[i].setPosition(pos_x, pos_y);
	 lines_cadre_[i].setFillColor(color);
 }

 void Cadre::setLines_grid(int i, float pos_x, float pos_y, sf::Color color, int largeur, int hauteur)
 {
	 lines_grid_.push_back(sf::RectangleShape(sf::Vector2f(largeur, hauteur)));
	 lines_grid_[i].setFillColor(color);
	 lines_grid_[i].setPosition(pos_x, pos_y);
 }

 void Cadre::setLines_menu(int i, float pos_x, float pos_y, sf::Color color, int largeur, int hauteur)
 {
	 lines_menu_.push_back(sf::RectangleShape(sf::Vector2f(largeur, hauteur)));
	 lines_menu_[i].setPosition(pos_x, pos_y);
	 lines_menu_[i].setFillColor(color);
 }

