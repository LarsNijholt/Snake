#include "SnakeGame.h"
#include "Window.h"

SnakeGame::SnakeGame() : m_window("Snake", sf::Vector2u(800, 600)), m_Snake(m_world.GetBlockSize(), &m_textbox), m_world(sf::Vector2u(800, 600))
{
	m_Clock.restart();
	srand(time(nullptr));

	m_textbox.Setup(5, 14, 350, sf::Vector2f(225, 0));
	m_textbox.Add("Seeded random number generator with " + std::to_string(time(nullptr)));
	m_Elapsed = 0.0f;
}
SnakeGame::~SnakeGame() {}

sf::Time SnakeGame::GetElapsed() { return m_Clock.getElapsedTime(); }
void SnakeGame::RestartClock() { m_Elapsed += m_Clock.restart().asSeconds(); }
Window* SnakeGame::GetWindow() { return &m_window; }

void SnakeGame::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_Snake.GetPhysicalDirection() != Direction::Down)
	{
		m_Snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_Snake.GetPhysicalDirection() != Direction::Up)
	{
		m_Snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_Snake.GetPhysicalDirection() != Direction::Right)
	{
		m_Snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_Snake.GetPhysicalDirection() != Direction::Left)
	{
		m_Snake.SetDirection(Direction::Right);
	}
}

void SnakeGame::Update()
{
	m_window.Update();
	float timeStep = 1.0f / m_Snake.GetSpeed();

	if (m_Elapsed >= timeStep)
	{
		m_Snake.Tick();
		m_world.Update(m_Snake);
		m_Elapsed -= timeStep;
		if (m_Snake.HasLost())
		{
			m_textbox.Add("GAME OVER! Score: " + std::to_string(m_Snake.GetScore()));
			if (m_Snake.GetScore() > _highScore) _highScore = m_Snake.GetScore();
			m_textbox.Add("High Score: " + std::to_string((long long)_highScore));
			m_Snake.Reset();
		}
	}
}

void SnakeGame::Render()
{
	m_window.BeginDraw();
	m_world.Render(*m_window.GetRenderWindow());
	m_Snake.Render(*m_window.GetRenderWindow());
	m_textbox.Render(*m_window.GetRenderWindow());
	m_window.EndDraw();
}