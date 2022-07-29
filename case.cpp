#include "case.h"
#include <cmath>

Case::Case() : sf::Text() {}

void Case::exchange(Case &c, sf::RenderWindow& window, Cadre cadre)
{
	float pos_tampon;
	std::string str;
	// Les nombres sont-ils dans la même ligne ?
	if (abs(c.getPosition().y - getPosition().y) < 50)	// 50 est une valeur choisie arbitrairement
	{
		// Les nombres sont-ils dans des cases adjacentes ?
		if (abs(c.getPosition().x - getPosition().x) < (window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 2 * cadre.getLargeur() / 8)
		{
			// On prend soin de prendre en compte le fait que la largeur du nombre en pixel peut changer (getGlobalBounds().width)
			pos_tampon = c.getPosition().x + c.getGlobalBounds().width / 2;
			c.setPosition(getPosition().x + getGlobalBounds().width  / 2 - c.getGlobalBounds().width / 2, c.getPosition().y);
			setPosition(pos_tampon - getGlobalBounds().width / 2, getPosition().y);
		}
	}
	// Les nombres sont-ils dans la même colonne ?
	if (abs(c.getPosition().x - getPosition().x) < 50)
	{
		// Les nombres sont-ils dans des cases adjacentes ?
		if (abs(c.getPosition().y - getPosition().y) < (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 2 * cadre.getLargeur() / 8)
		{
			// Ici, la hauteur ne change pas d'un nombre à un autre <
			pos_tampon = c.getPosition().y;
			c.setPosition(c.getPosition().x, getPosition().y);
			setPosition(getPosition().x, pos_tampon);
		}
	}
}