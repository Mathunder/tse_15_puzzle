#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
/*
// Affichage de la grille
void drawGrid(sf::RenderWindow& window) {
	std::vector<sf::RectangleShape> lines;
	// Lignes verticales
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 1000))); // Vector2f(épaisseur en x, épaisseur en y)
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 1000)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 1000)));
	// Lignes horizontales
	lines.push_back(sf::RectangleShape(sf::Vector2f(1000, 6)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(1000, 6)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(1000, 6)));
	
	// Positionnement des lignes
	int pos[6] = { (window.getDefaultView().getSize().x / 4) - (lines[0].getSize().x) / 2,
		 (window.getDefaultView().getSize().x / 4) + (window.getDefaultView().getSize().x / 4) - (lines[1].getSize().x) / 2,
		 2*(window.getDefaultView().getSize().x /4) + (window.getDefaultView().getSize().x / 4) - (lines[2].getSize().x) / 2,
		(window.getDefaultView().getSize().y / 4) - (lines[3].getSize().y) / 2,
		(window.getDefaultView().getSize().y / 4) + (window.getDefaultView().getSize().y / 4) - (lines[4].getSize().y) / 2,
	2*(window.getDefaultView().getSize().y / 4) + (window.getDefaultView().getSize().y / 4) - ((lines[5].getSize().y) / 2)};
	
	lines[0].setPosition(pos[0], 0);
	lines[1].setPosition(pos[1], 0);
	lines[2].setPosition(pos[2], 0);
	lines[3].setPosition(0, pos[3]);
	lines[4].setPosition(0, pos[4]);
	lines[5].setPosition(0, pos[5]);
	// Lignes de couleurs noires
	for (size_t i = 0; i < lines.size(); i++)
		lines[i].setFillColor(sf::Color::Black);
	// Affichage
	for (size_t i = 0; i < lines.size(); i++)
		window.draw(lines[i]);
}

// Affichage d'une croix
void drawCross(sf::RenderWindow& window, size_t i, size_t j) {
	// Deux lignes tournées de 45°
	sf::RectangleShape r1(sf::Vector2f(4, 80));
	sf::RectangleShape r2(sf::Vector2f(4, 80));
	// Par défaut, l'origine est en haut à droite du rectangle
	// On met l'origine au milieu pour simplifier les calculs
	r1.setOrigin(2, 40);
	r2.setOrigin(2, 40);// Positionnement
	r1.setPosition(i * 100 + 50, j * 100 + 50);
	r2.setPosition(i * 100 + 50, j * 100 + 50);
	// Rotation
	r1.rotate(45);
	r2.rotate(-45);
	// Coueleur bleu
	r1.setFillColor(sf::Color::Blue);
	r2.setFillColor(sf::Color::Blue);
	// Affichage
	window.draw(r1);
	window.draw(r2);
}

// Affichage d'un cercle
void drawCircle(sf::RenderWindow& window, size_t i, size_t j) {
	// Rayon = 30px
	sf::CircleShape c(30);
	// Contour rouge d'une épaisseur de 4px
	c.setOutlineColor(sf::Color::Red);
	c.setOutlineThickness(4);
	c.setOrigin(30, 30);
	c.setPosition(i * 100 + 50, j * 100 + 50); 
	window.draw(c);
}

int main()
{
	// Création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Jeu de morpion"); // VideMode(hauteur, largeur)
	// Tableau de jeu
	int tab[3][3];
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			tab[i][j] = 0;
	// Indique le tour du joueur rouge
	bool redTurn = true;
	// Compte le nombre de cases vide
	int nbLeft = 9;
	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
			// Appui sur le bouton gauche
			if ((event.type == sf::Event::MouseButtonPressed)
				&& (event.mouseButton.button == sf::Mouse::Left)) {
				// Si on a plus de place, on vide le tableau
				if (nbLeft == 0) {
					for (size_t i = 0; i < 3; i++)
						for (size_t j = 0; j < 3; j++)
							tab[i][j] = 0;
					nbLeft = 9;
				}
				// Sinon, on place notre jeton
				else {
					// Position de la souris dans par rapport à la fenêtre
					sf::Vector2i localPosition = sf::Mouse::getPosition(window);
					// Position de la souris dans le tableau
					localPosition /= 100;// Affichage console des coordonées
					std::cout << localPosition.x << " " << localPosition.y << std::endl;
					// Si on tombe sur une case vide
					if (tab[localPosition.x][localPosition.y] == 0) {
						// On remplie en fonction du tour du joueur (1 pour rouge, 2 pour bleu)
						tab[localPosition.x][localPosition.y] = redTurn ? 1 : 2;
						// On change de joueur
						redTurn = !redTurn;
						// On met a jour le nombre de cases vides
						nbLeft--;
					}
				}
			}
		}
		// On efface la fenêtre (en blanc)
		window.clear(sf::Color::White);
		// On affiche la grille
		drawGrid(window);
		// Parcours du tableau
		for (size_t i = 0; i < 3; i++) {
			for (size_t j = 0; j < 3; j++) {
				// Affichage du jeton
				if (tab[i][j] == 1)
					drawCircle(window, i, j);
				else if (tab[i][j] == 2)
					drawCross(window, i, j);
			}
		}
		// Mise à jour de la fenêtre
		window.display();
	}return 0;
}
*/