#include <SFML/Graphics.hpp>
#include "Game.h"
#include<filesystem>
#include<iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Game Window");
	sf::Texture ducktexture;
	if (!ducktexture.loadFromFile("/Assets/Duck.jpg"))
		return EXIT_FAILURE;
	sf::Sprite Duck(ducktexture);
	sf::Vector2u size = ducktexture.getSize();
	//Duck.setOrigin()
	return 0;
}
