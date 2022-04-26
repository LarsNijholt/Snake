#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	//create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::Texture texture;
	if (!texture.loadFromFile("C:/Users/larsn/source/repos/SFMLGame/SFML/Assets/Duck.jpg"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}
	return 0;
}
