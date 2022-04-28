#include <SFML/Graphics.hpp>
#include "Game.h"
#include<filesystem>
#include<iostream>

int main()
{
	//create the window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window");
	sf::Texture texture;
	auto path = std::filesystem::current_path();
	if (!texture.loadFromFile(path.generic_string() + "/Assets/Duck.jpg"))
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
