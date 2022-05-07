#include "Textbox.h"

Textbox::Textbox()
{
	Setup(5, 9, 200, sf::Vector2f(0, 0));
}

Textbox::Textbox(int _visible, int _charSize, int _width, sf::Vector2f _screenPos)
{
	Setup(_visible, _charSize, _width, _screenPos);
}

Textbox::~Textbox() { Clear(); }

void Textbox::Setup(int _visible, int _charSize, int _width, sf::Vector2f _screenPos)
{
	m_numVisible = _visible;
	sf::Vector2f _offset(2.0f, 2.0f);

	m_font.loadFromFile("arial.ttf");
	m_content.setFont(m_font);
	m_content.setString("");
	m_content.setCharacterSize(_charSize);
	m_content.setFillColor(sf::Color::White);
	m_content.setPosition(_screenPos + _offset);

	m_backdrop.setSize(sf::Vector2f(_width, (_visible * (_charSize * 1.2f))));
	m_backdrop.setFillColor(sf::Color(90, 90, 90, 90));
	m_backdrop.setPosition(_screenPos);
}

void Textbox::Add(std::string _message)
{
	m_messages.push_back(_message);
	if (m_messages.size() < 6) { return; }
	m_messages.erase(m_messages.begin());
}

void Textbox::Clear() { m_messages.clear();}

void Textbox::Render(sf::RenderWindow& _wind)
{
	std::string _content;

	for (auto& itr : m_messages)
	{
		_content.append(itr + "\n");
	}

	if (_content != "")
	{
		m_content.setString(_content);
		_wind.draw(m_backdrop);
		_wind.draw(m_content);
	}
}