#include <SFML/Graphics.hpp>

int main() {
	sf::Texture texture;
	// il faut bien pr�ciser l'arborescence de l'image que l'on veut ouvrir
	if (!texture.loadFromFile("C:/Users/Matthieu/Pictures/Saved Pictures/Berserk Wallpaper 2.jpg"))
	{
		// erreur...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	// Cr�ation de la fen�tre
	sf::Vector2u sz = texture.getSize();
	sf::RenderWindow window(sf::VideoMode(sz.y, sz.x), "image");	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			// Demande de fermeture de la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// On efface la fen�tre (en blanc)
		window.clear(sf::Color::White);
		// Affichage du sprite
		window.draw(sprite);
		// Mise � jour de la fen�tre
		window.display();
	}
	return 0;
}