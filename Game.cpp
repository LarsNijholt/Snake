#include "Game.h"

Game::Game() : m_window("Game window", sf::Vector2u(800, 600))
{
	//setting up class members.
	if (!m_mushroomTexture.loadFromFile("Assets/Mushroom.png"))
		printf("Cannot load texture at 'Root'/Assets/Mushroom.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(400, 400);
}

Game::~Game() {}
Window* Game::GetWindow() { return &m_window; }
void Game::HandleInput() 
{
	//Handle input
}

void Game::Update()
{
	m_window.Update(); // Update window events.
	MoveSprite();
}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }

void Game::MoveSprite()
{
	sf::Vector2u windSize = m_window.GetWindowSize();
	sf::Vector2u textSize = m_mushroomTexture.getSize();

	if ((m_mushroom.getPosition().x > windSize.x - textSize.x && m_increment.x > 0) || (m_mushroom.getPosition().x < 0 && m_increment.x < 0))
	{
		m_increment.x = -m_increment.x;
	}

	if ((m_mushroom.getPosition().y > windSize.y - textSize.y && m_increment.y > 0) || (m_mushroom.getPosition().y < 0 && m_increment.y < 0))
	{
		m_increment.y = -m_increment.y;
	}

	float fElapsed = m_elapsed.asSeconds();

	m_mushroom.setPosition(m_mushroom.getPosition().x + (m_increment.x * fElapsed), m_mushroom.getPosition().y + (m_increment.y * fElapsed));
}

void Game::Render()
{
	m_window.BeginDraw(); // Clear.
	m_window.Draw(m_mushroom);
	m_window.EndDraw(); // Display.
}

void Game::GetTime()
{
	sf::Clock clock;
	sf::Time time = clock.getElapsedTime();
	float seconds = time.asSeconds();
	sf::Int32 milliseconds = time.asMilliseconds();
	sf::Int64 microseconds = time.asMicroseconds();

	time = clock.restart();
}