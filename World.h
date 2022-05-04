#pragma once
#include "Window.h"

class Snake;

class World
{
public:
	World(sf::Vector2u windSize);
	~World();

	int GetBlockSize();

	void RespawnApple();

	void Update(Snake& _player);
	void Render(sf::RenderWindow& _window);
private:
	sf::Vector2u _windowSize;
	sf::Vector2i m_item;
	int m_blockSize = 0;

	sf::CircleShape m_appleShape;
	sf::RectangleShape m_bounds[4];
};