#include "Game.h"

Game::Game() : m_window("Game window", sf::Vector2u(800, 600))
{
	//setting up class members.
	if (!m_duckTexture.loadFromFile("Assets/Duck.jpg"))
		printf("Cannot load texture at 'Root'/Assets/Duck.jpg");
	m_duck.setTexture(m_duckTexture);
	m_increment = sf::Vector2i(4, 4);
}

Game::~Game() {}
Window* Game::GetWindow() { return &m_window; }

void Game::Update()
{
	m_window.Update(); // Update window events.
	MoveDuck();
}

void Game::MoveDuck()
{
	sf::Vector2u windSize = m_window.GetWindowSize();
	sf::Vector2u textSize = m_duckTexture.getSize();

	if ((m_duck.getPosition().x > windSize.x - textSize.x && m_increment.x > 0) || (m_duck.getPosition().x < 0 && m_increment.x < 0))
	{
		m_increment.x = -m_increment.x;
	}

	if ((m_duck.getPosition().y > windSize.x - textSize.x && m_increment.x > 0) || (m_duck.getPosition().y < 0 && m_increment.y < 0))
	{
		m_increment.y = -m_increment.y;
	}

	m_duck.setPosition(m_duck.getPosition().x + m_increment.x, m_duck.getPosition().y + m_increment.y);
}

void Game::Render()
{
	m_window.BeginDraw(); // Clear.
	m_window.Draw(m_duck);
	m_window.EndDraw(); // Display.
}