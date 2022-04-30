#pragma once
#include "Window.h"

class Game
{
public:
	Game();
	~Game();

	//void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();

private:
	void MoveDuck();
	Window m_window;

	sf::Texture m_duckTexture;
	sf::Sprite m_duck;
	sf::Vector2i m_increment;

};