#include "World.h"
#include "Snake.h"

World::World(sf::Vector2u _windSize)
{
	m_blockSize = 16;

	_windowSize = _windSize;
	RespawnApple();
	m_appleShape.setFillColor(sf::Color::Red);
	m_appleShape.setRadius(m_blockSize / 2);
	
	for (size_t i = 0; i < 4; i++)
	{
		m_bounds[i].setFillColor(sf::Color(150, 0, 0));
		if (!((i + 1) % 2))
		{
			m_bounds[i].setSize(sf::Vector2f(_windowSize.x, m_blockSize));
		}
		else
		{
			m_bounds[i].setSize(sf::Vector2f(_windowSize.x, m_blockSize));
		}
		if (i < 2)
		{
			m_bounds[i].setPosition(0, 0);
		}
		else
		{
			m_bounds[i].setOrigin(m_bounds[i].getSize());
			m_bounds[i].setPosition(sf::Vector2f(_windowSize));
		}
	}
}

World::~World(){}

void World::RespawnApple()
{
	int maxX = (_windowSize.x / m_blockSize) - 2;
	int maxY = (_windowSize.y / m_blockSize) - 2;
	m_item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	m_appleShape.setPosition(m_item.x * m_blockSize, m_item.y * m_blockSize);
}

void World::Update(Snake& _player)
{
	if (_player.GetPosition() == m_item)
	{
		_player.Extend();
		_player.IncreaseScore();
		RespawnApple();
	}

	int gridSize_x = _windowSize.x / m_blockSize;
	int gridSize_y = _windowSize.y / m_blockSize;

	if (_player.GetPosition().x <= 0 ||
		_player.GetPosition().y <= 0 ||
		_player.GetPosition().x >= gridSize_x - 1 ||
		_player.GetPosition().y >= gridSize_y - 1)
	{
		_player.Lose();
	}
}

void World::Render(sf::RenderWindow& _window)
{
	for (int i = 0; i < 4; i++)
	{
		_window.draw(m_bounds[i]);
	}
	_window.draw(m_appleShape);
}

int World::GetBlockSize() { return m_blockSize; }