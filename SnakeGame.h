#pragma once
#include "World.h"
#include "Snake.h"

class SnakeGame
{
public:
	SnakeGame();
	~SnakeGame();
	sf::Time GetElapsed();
	void RestartClock();
	void Update();
	void Render();
	void HandleInput();
	Window* GetWindow();
private:
	
	Window m_window;
	World m_world;
	Snake m_Snake;
	Textbox m_textbox;
	float m_Elapsed;
	sf::Clock m_Clock;
	int _highScore = 0;
};