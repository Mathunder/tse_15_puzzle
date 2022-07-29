#include "fonctions.h"
#include <fstream>

// Cette fonction affiche le plateau de jeu
void drawPlateau(Cadre cadre, sf::RenderWindow& window)
{
	// --> Mise en place des 4 lignes composant le cadre
	// Ligne du haut
	cadre.setLines_cadre(0, (window.getDefaultView().getSize().x - cadre.getLargeur()) / 2, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2, sf::Color::Black, window.getDefaultView().getSize().x - (window.getDefaultView().getSize().x - cadre.getLargeur()), 6);
	// ligne de gauche
	cadre.setLines_cadre(1, (window.getDefaultView().getSize().x - cadre.getLargeur()) / 2, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2, sf::Color::Black, 6, window.getDefaultView().getSize().y - (window.getDefaultView().getSize().y - cadre.getLargeur()));
	// Ligne de droite
	cadre.setLines_cadre(2, (window.getDefaultView().getSize().x + cadre.getLargeur()) / 2, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2, sf::Color::Black, 6, window.getDefaultView().getSize().y - (window.getDefaultView().getSize().y - cadre.getLargeur()) + 6);
	// Ligne du bas
	cadre.setLines_cadre(3, (window.getDefaultView().getSize().x - cadre.getLargeur()) / 2, (window.getDefaultView().getSize().y + cadre.getLargeur()) / 2, sf::Color::Black, window.getDefaultView().getSize().x - (window.getDefaultView().getSize().x - cadre.getLargeur()), 6);

	// --> Mise en place des 6 lignes composant la grille de jeu
	float tab[4] = { (window.getDefaultView().getSize().x - cadre.getLargeur()) / 2, (window.getDefaultView().getSize().y - cadre.getLargeur()) / 2, (window.getDefaultView().getSize().x + cadre.getLargeur()) / 2,(window.getDefaultView().getSize().y + cadre.getLargeur()) / 2 };
	// Lignes verticales
	cadre.setLines_grid(0, tab[1] + cadre.getLargeur() / 4, tab[0], sf::Color::Black, 6, cadre.getLargeur());
	cadre.setLines_grid(1, tab[1] + cadre.getLargeur() / 2, tab[0], sf::Color::Black, 6, cadre.getLargeur());
	cadre.setLines_grid(2, tab[1] + 3 * cadre.getLargeur() / 4, tab[0], sf::Color::Black, 6, cadre.getLargeur());
	// Lignes horizontales
	cadre.setLines_grid(3, tab[1], tab[0] + cadre.getLargeur() / 4, sf::Color::Black, cadre.getLargeur(), 6);
	cadre.setLines_grid(4, tab[1], tab[0] + cadre.getLargeur() / 2, sf::Color::Black, cadre.getLargeur(), 6);
	cadre.setLines_grid(5, tab[1], tab[0] + 3 * cadre.getLargeur() / 4, sf::Color::Black, cadre.getLargeur(), 6);

	// --> Affichage de toutes les lignes (cadre + grille + menu)
	// Affichage des lignes composant le cadre
	for (int i = 0; i < cadre.getLines_cadre().size(); i++)
		window.draw(cadre.getLines_cadre()[i]);
	// Affichage de la grille de jeu
	for (int i = 0; i < cadre.getLines_grid().size(); i++)
		window.draw(cadre.getLines_grid()[i]);
}

// Cette fonction affiche le menu principal du jeu (= accueil) et retourne un entier correspondant au choix fait par le joueur
int menu_jeu(sf::RenderWindow& window, sf::Texture texture, sf::Font font, Case cases[16], Cadre cadre)
{
	// initialisation de la valeur retourneé
	int choice = 0;

	// Création des différents boutons qui vont constituer le menu principal du jeu
	sf::Text jeu("Nouvelle partie", font, 100);
	jeu.setPosition(sf::Vector2f((window.getDefaultView().getSize().x - jeu.getGlobalBounds().width) / 2, window.getDefaultView().getSize().y / 3.5));
	jeu.setFillColor(sf::Color::Black);

	sf::Text quitter("Quitter", font, 40);
	quitter.setPosition(sf::Vector2f((window.getDefaultView().getSize().x - quitter.getGlobalBounds().width) / 2, window.getDefaultView().getSize().y / 1.5));
	quitter.setFillColor(sf::Color::Black);

	sf::Text charger("Charger partie", font, 50);
	charger.setPosition(sf::Vector2f((window.getDefaultView().getSize().x - charger.getGlobalBounds().width) / 2, window.getDefaultView().getSize().y / 2));
	charger.setFillColor(sf::Color::Black);

	// Pour des boutons plus sympathiques, on les fait se souligner et afficher en blanc lorsqu'ils sont survolés
	charger = IsTextPointed(window, charger);
	jeu = IsTextPointed(window, jeu);
	quitter = IsTextPointed(window, quitter);

	// Affichage des boutons
	window.draw(charger);
	window.draw(jeu);
	window.draw(quitter);

	// On regarde si il y a un appui sur les boutons
	if (IsTextPressed(window, jeu))
	{
		melange(cases, window, cadre);
		choice = 1;
	}

	if (IsTextPressed(window, quitter))
		choice = 2;

	if (IsTextPressed(window, charger))
	{
		choice = 1;
		choice = charger_sauvegarde(cases, font, window);
	}

	return choice;
}

// Cette fonction permet de savoir si un bouton (de type sf::Text) est en train d'être cliqué
bool IsTextPressed(sf::RenderWindow& window, sf::Text text)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// Position de la souris par rapport à la fenêtre
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		if (text.getGlobalBounds().contains(localPosition.x, localPosition.y))
			return true;
		else
			return false;
	}
	else
		return false;
}

// Cette fonction permet de souligner et colorer en blanc le bouton que la souris survole.
// Plus précisemment, elle prend en argument un bouton ainsi qu'un type sf::RenderWindow, et elle renovie un bouton, souligné et en blanc ou non selon s'il est cliqué
// Elle est purement esthétique.
sf::Text IsTextPointed(sf::RenderWindow& window, sf::Text text)
{
	if (text.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Underlined);
	}
	else
	{
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Regular);
	}
	return text;
}

// Cette fonction permet de sauvegarder une partie, et renvoie un entier correspondant au choix fait par l'utilisateur
int sauvegarder(Case cases[16], sf::Font font, sf::RenderWindow& window)
{
	std::ofstream ofs("sauvegarde.txt");
	int choice = 1;
	for (int i = 0; i < 16; i++)
	{
		ofs << cases[i].getPosition().x << std::endl;
		ofs << cases[i].getPosition().y << std::endl;
	}
	/*
	else
	{
		sf::Text str1("Une sauvegarde existe déja.", font, 50);
		str1.setPosition((window.getDefaultView().getSize().x - str1.getGlobalBounds().width) / 2, window.getDefaultView().getSize().y / 2.5);
		str1.setFillColor(sf::Color::Black);
		sf::Text str2("Ecraser l'ancienne sauvegarde ?", font, 50);
		str2.setPosition((window.getDefaultView().getSize().x - str2.getGlobalBounds().width) / 2, window.getDefaultView().getSize().y / 1.8);
		str2.setFillColor(sf::Color::Black);
		sf::Text str3("Oui", font, 50);
		str3.setPosition(2*(window.getDefaultView().getSize().x - str3.getGlobalBounds().width) / 3, window.getDefaultView().getSize().y / 1.4);
		str3.setFillColor(sf::Color::Black);
		sf::Text str4("Non", font, 50);
		str4.setPosition((window.getDefaultView().getSize().x - str4.getGlobalBounds().width) / 3, window.getDefaultView().getSize().y / 1.4);
		str4.setFillColor(sf::Color::Black);
		sf::Text str5("Partie sauvegardée !", font, 50);
		str5.setPosition((window.getDefaultView().getSize().x - str5.getGlobalBounds().width) / 3, window.getDefaultView().getSize().y / 2);
		str5.setFillColor(sf::Color::Black);

		str3 = IsTextPointed(window, str3);
		str4 = IsTextPointed(window, str4);
		window.draw(str1);
		window.draw(str2);
		window.draw(str3);
		window.draw(str4);

		if (IsTextPressed(window, str3))
		{
			ofs << 1 << std::endl;
			for (int i = 0; i < 16; i++)
			{
				ofs << cases[i].getPosition().x << std::endl;
				ofs << cases[i].getPosition().y << std::endl;
			}
			window.draw(str5);
		}
		if (IsTextPressed(window, str4))
			choice = 1;
	}*/
	return choice;
}

// Cette fonction permet de charger une sauvegarde et renvoie un entier correspondant au choix fait pas l'utilisateur
int charger_sauvegarde(Case cases[16], sf::Font font, sf::RenderWindow& window)
{
	std::ifstream ifs("sauvegarde.txt");
	int choice = 1;
	float x, y;
	for (int i = 0; i < 16; i++)
	{
		ifs >> x;
		ifs >> y;
		cases[i].setPosition(x, y);
	}
	return choice;
}

// Cette fonction permet de mélanger les cases en partant de la solution (le jeu est donc toujours solvable)
void melange(Case cases[16], sf::RenderWindow& window, Cadre cadre)
{
	srand(time(NULL));
	int hasard;
	for (int i = 0; i < 30; i++)
	{
		hasard = rand() % 15;
		cases[hasard].exchange(cases[15], window, cadre);
	}
}

// Cette fonction affiche le menu de fin de jeu et renvoie un entier correspondant au choix fait par l'utilisateur
int fin_jeu(sf::RenderWindow& window, sf::Texture texture, sf::Font font)
{
	int choice = 4;

	sf::Text congrats("Félicitations !", font, 100);
	congrats.setPosition(sf::Vector2f((window.getDefaultView().getSize().x - congrats.getGlobalBounds().width) / 2, window.getDefaultView().getSize().y / 3.5));
	congrats.setFillColor(sf::Color::Black);

	sf::Text rejouer("Rejouer", font, 40);
	rejouer.setPosition(sf::Vector2f((window.getDefaultView().getSize().x - rejouer.getGlobalBounds().width) / 2, window.getDefaultView().getSize().y / 1.5));
	rejouer.setFillColor(sf::Color::Black);

	sf::Text quitter("Quitter", font, 50);
	quitter.setPosition(sf::Vector2f((window.getDefaultView().getSize().x - quitter.getGlobalBounds().width) / 2, window.getDefaultView().getSize().y / 2));
	quitter.setFillColor(sf::Color::Black);

	rejouer = IsTextPointed(window, rejouer);
	quitter = IsTextPointed(window, quitter);
	window.draw(rejouer);
	window.draw(quitter);
	window.draw(congrats);

	if (IsTextPressed(window, rejouer)) 
		choice = 1;
	if (IsTextPressed(window, quitter))	
		choice = 2;
	return choice;
}

// Cette fonction vérifie si le joueur a gagné et renoive un booléen selon le cas
bool win(Case cases[16], std::vector<sf::Vector2f> center_of_cells)
{
	bool victoire = false;
	int int1, int2 = 0;
	int a = 0;

	for (int i = 0; i < 16; i++)
	{
		/*std::cout << i << std::endl;
		std::cout << "cases[i].getPosition().x : " << cases[i].getPosition().x + cases[i].getGlobalBounds().width / 2 << std::endl;
		std::cout << "center_of_cells[i].x : " << center_of_cells[i].x << std::endl;
		std::cout << "cases[i].getPosition().y : " << cases[i].getPosition().y + cases[i].getGlobalBounds().height / 1.5 << std::endl;
		std::cout << "center_of_cells[i].y : " << center_of_cells[i].y << std::endl;
		std::cout << std::endl;	*/	
		
		int1 = cases[i].getPosition().x + cases[i].getGlobalBounds().width / 2 - center_of_cells[i].x;
		int2 = cases[i].getPosition().y + cases[i].getGlobalBounds().height / 1.5 - center_of_cells[i].y;
		
		// std::cout << "int1 : " << int1 << std::endl << "int2 : " << int2 << std::endl << std::endl;
		if ((int1 == 0) && (int2 == 0))
		{
			a += 1;
		}
	}
	
	if (a == 16)
		victoire = true;
	return victoire;
}