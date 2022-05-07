#pragma once
#include "Window.h"

using MessageContainer = std::vector<std::string>;

class Textbox
{
public:
	Textbox();
	Textbox(int _visible, int _charSize, int _width, sf::Vector2f _screenPos);
	~Textbox();

	void Setup(int _visible, int _charSize, int _width, sf::Vector2f _screenPos);
	void Add(std::string _message);
	void Clear();

	void Render(sf::RenderWindow& _wind);

private:
	MessageContainer m_messages;
	int m_numVisible;
	sf::RectangleShape m_backdrop;
	sf::Font m_font;
	sf::Text m_content;
};