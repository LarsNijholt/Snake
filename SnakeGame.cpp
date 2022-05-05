#include "SnakeGame.h"
#include "Window.h"

SnakeGame::SnakeGame() : m_window("Snake", sf::Vector2u(800, 600)), m_Snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600))
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_Snake.GetDirection() != Direction::Down)
	{
		m_Snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_Snake.GetDirection() != Direction::Up)
	{
		m_Snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_Snake.GetDirection() != Direction::Right)
	{
		m_Snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_Snake.GetDirection() != Direction::Left)
	{
		m_Snake.SetDirection(Direction::Right);
	}
}

sf::Time SnakeGame::GetElapsed() { return m_Elapsed; }
void SnakeGame::RestartClock() { m_Elapsed = m_Clock.restart(); }

void SnakeGame::Update()
{
	float timeStep = 1.0f / m_Snake.GetSpeed();
	float Felapsed = m_Elapsed.asSeconds();

	if (Felapsed >= timeStep)
	{
		m_Snake.Tick();
		m_world.Update(m_Snake);
		Felapsed -= timeStep;
		if (m_Snake.HasLost())
		{
			m_Snake.Reset();
		}
	}
}

void SnakeGame::Render()
{
	m_window.BeginDraw();
	m_world.Render(*m_window.GetWindowSize())
}