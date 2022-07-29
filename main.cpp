#include "fonctions.h"
#include "case.h"
#include <fstream>

int main()
{
	// Initialisation de la texture qui constituera le fond d'écran de la fenêtre
	sf::Texture texture;
	// chemin à modifier si besoin
	texture.loadFromFile("Background2.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(0.3, 0.3));
	sprite.setOrigin(texture.getSize().x / 6, texture.getSize().y / 6);

	// Création de la fenêtre dans laquelle le jeu va s'afficher
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Jeu de Taquin"); // VideoMode(hauteur, largeur)
	
	// Initialisation du cadre
	Cadre cadre(700);

	// Initialisation de la police d'écriture
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/ariblk.ttf");
	
	// --> Mise en place du menu simplifié une fois la partie lancée
	sf::Text menu("Menu", font, 35);
	sf::Text save("Save", font, 35);
	sf::Text exit("Exit", font, 35);
	sf::Text again("Relancer une partie", font, 35);
	menu.setPosition(window.getDefaultView().getSize().x / 2 - 3 * save.getGlobalBounds().width, (window.getSize().y - cadre.getLargeur() * 1.2) / 2);
	menu.setFillColor(sf::Color::Black);
	save.setPosition((window.getDefaultView().getSize().x - save.getGlobalBounds().width) / 2, (window.getSize().y - cadre.getLargeur() * 1.2) / 2);
	save.setFillColor(sf::Color::Black);
	exit.setPosition((window.getDefaultView().getSize().x + 1.5 * save.getGlobalBounds().width) / 2 + save.getGlobalBounds().width, (window.getSize().y - cadre.getLargeur() * 1.2) / 2);
	exit.setFillColor(sf::Color::Black);
	again.setPosition((window.getDefaultView().getSize().x - again.getGlobalBounds().width) / 2, (window.getDefaultView().getSize().y + 1.1*cadre.getLargeur()) / 2);
	again.setFillColor(sf::Color::Black);

	// --> Mise en place des lignes séparant les options du menu simplifié
	cadre.setLines_menu(0, window.getDefaultView().getSize().x / 2 - save.getGlobalBounds().width, (window.getSize().y - cadre.getLargeur() * 1.2) / 2, sf::Color::Black, 4, 50);
	cadre.setLines_menu(1, (window.getDefaultView().getSize().x + 0.5 * save.getGlobalBounds().width) / 2 + save.getGlobalBounds().width, (window.getSize().y - cadre.getLargeur() * 1.2) / 2, sf::Color::Black, 4, 50);
	// Initialisation du choix
	int choice = 0;
	
	// Tableau destiné à remplir les cases
	std::string num[16] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" };
	
	// Contient les coordonnées du centre de chaque case, de gauche à droite puis de bas en haut : { case 1, case 2, case 3, case 4; ..., case 16 };
	std::vector<sf::Vector2f> center_of_cells = { 
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 1 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 1 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 3 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 1 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 5 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 1 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 7 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 1 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 1 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 3 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 3 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 3 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 5 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 3 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 7 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 3 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 1 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 5 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 3 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 5 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 5 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 5 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 7 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 5 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 1 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 7 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 3 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 7 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 5 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 7 * cadre.getLargeur() / 8),
	sf::Vector2f((window.getDefaultView().getSize().x - cadre.getLargeur()) / 2 + 7 * cadre.getLargeur() / 8, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2 + 7 * cadre.getLargeur() / 8)
	};

	// Déclaration et remplissage des cases
	Case cases[16];
	for (int i = 0; i < 16; i++)
	{
		cases[i].setString(num[i]);
		cases[i].setFont(font);
		cases[i].setCharacterSize(80);
		cases[i].setPosition(center_of_cells[i].x - cases[i].getGlobalBounds().width / 2, center_of_cells[i].y - cases[i].getGlobalBounds().height / 1.5);
		cases[i].setFillColor(sf::Color::Black);
	}
	// Le 16 de la 15e case du tableau est transparent
	cases[15].setFillColor(sf::Color::Transparent);
	// Les cases sont mélangées
	melange(cases, window, cadre);
	
	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		// Affichage du sprite (fond d'écran)
		window.draw(sprite);

		// Affichage du menu principal
		if (choice == 0)
			choice = menu_jeu(window, texture, font, cases, cadre);
		// Exécution des différents scénarios selon ce que le l'utilisateur choisit de faire
		else
		{
			switch (choice)
			{
			// Cas de base où le joueur souhaite lancer une nouvelle partie
			case 1:
				// Affichage du cadre
				drawPlateau(cadre, window);
				// Mise en place des boutons "sympathiques" qui s'affichent en blanc et sont soulignés lorsqu'ils sont survolés
				menu = IsTextPointed(window, menu);
				save = IsTextPointed(window, save);
				exit = IsTextPointed(window, exit);
				again = IsTextPointed(window, again);
				// Affichage des différents menus et du cadre de jeu
				window.draw(menu);
				window.draw(save);
				window.draw(exit);
				window.draw(again);
				window.draw(cadre.getLines_menu()[0]);
				window.draw(cadre.getLines_menu()[1]);
				// Affichage des cases
				for (int i = 0; i < 16; i++)
					window.draw(cases[i]);
				// Détection des boutons pressés
				if (IsTextPressed(window, again))
					melange(cases, window, cadre);
				if (IsTextPressed(window, menu))
					choice = 0;
				if (IsTextPressed(window, exit))
					choice = 2;
				if (IsTextPressed(window, save))
					choice = 3;
				// Echange des cases lorsque l'utilisateur clique sur une case adjacente à la case vide
				for (int i = 0; i < 15; i++)
				{
					if (IsTextPressed(window, cases[i]))
						cases[i].exchange(cases[15], window, cadre);
				}

				// Verification des cases : le joueur a-t-il gagné ?
				if (win(cases, center_of_cells))
					choice = 4;
				break;
			
			// Cas où le joueur souhaite quitter le jeu
			case 2:
				window.close();
				sauvegarder(cases, font, window);
				break;

			// Cas où le jouer sauvegarde sa partie
			case 3:
				choice = sauvegarder(cases, font, window);
				break;

			// Cas où le joueur gagne
			case 4:
				choice = fin_jeu(window, texture, font);
				/*srand(time(NULL));
				int hasard;
				for (int i = 0; i < 700; i++)
				{
					hasard = rand() % 14;
					cases[hasard].exchange(cases[15], window, cadre);
				}*/
				break;
			}
		}
		// Affichage de la fenêtre
		window.display();
	}
}