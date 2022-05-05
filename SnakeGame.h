#pragma once
#include "World.h"
#include "Snake.h"

class SnakeGame
{
public:
	SnakeGame();
	sf::Time GetElapsed();
	void RestartClock();
private:
	void Update();
	void Render();
	Window m_window;
	World m_world;
	Snake m_Snake;
	sf::Time m_Elapsed;
	sf::Clock m_Clock;
};