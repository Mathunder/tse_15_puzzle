#pragma once
#include "affichage.h"
#include "case.h"

// Cette fonction affiche le plateau de jeu
void drawPlateau(Cadre cadre, sf::RenderWindow& window);

// Cette fonction affiche le menu principal du jeu (= accueil) et retourne un entier correspondant au choix fait par le joueur
int menu_jeu(sf::RenderWindow& window, sf::Texture texture, sf::Font font,  Case cases[16], Cadre cadre);

// Cette fonction permet de savoir si un bouton (de type sf::Text) est en train d'être cliqué
bool IsTextPressed(sf::RenderWindow& window, sf::Text text);

// Cette fonction permet de souligner et colorer en blanc le bouton que la souris survole.
// Plus précisemment, elle prend en argument un bouton ainsi qu'un type sf::RenderWindow, et elle renovie un bouton, souligné et en blanc ou non selon s'il est cliqué
// Elle est purement esthétique.
sf::Text IsTextPointed(sf::RenderWindow& window, sf::Text text);

// Cette fonction permet de sauvegarder une partie, et renvoie un entier correspondant au choix fait par l'utilisateur
int sauvegarder(Case cases[16], sf::Font font, sf::RenderWindow& window);

// Cette fonction permet de charger une sauvegarde et renvoie un entier correspondant au choix fait pas l'utilisateur
int charger_sauvegarde(Case cases[16], sf::Font font, sf::RenderWindow& window);

// Cette fonction permet de mélanger les cases en partant de la solution (le jeu est donc toujours solvable)
void melange(Case cases[16], sf::RenderWindow& window, Cadre cadre);

// Cette fonction affiche le menu de fin de jeu et renvoie un entier correspondant au choix fait par l'utilisateur
int fin_jeu(sf::RenderWindow& window, sf::Texture texture, sf::Font font);

// Cette fonction vérifie si le joueur a gagné et renoive un booléen selon le cas
bool win(Case cases[16], std::vector<sf::Vector2f> center_of_cells);