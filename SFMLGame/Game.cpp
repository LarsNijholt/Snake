#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game GameRef;

	sf::Window window;
	window.create(sf::VideoMode(2560, 1440), "My Game Window");
	window.setVerticalSyncEnabled(true); // sets vsync
	window.setFramerateLimit(60); // sets framerate
	while (window.isOpen())
	{
		// Check all the window's events that were triggered since the last iteration of the loop.
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				printf("the window will now close");
				window.close();
				break;

			case sf::Event::KeyPressed:
				break;

			case sf::Event::LostFocus:
				break;

			default:
				break;
			}
		}

		if (event.type == sf::Event::LostFocus)
		{
			GameRef.PrintString();
		}
	}
	return 0;
}

void Game::PrintString()
{
	printf("Lost Focus");
}
