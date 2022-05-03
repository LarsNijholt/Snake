#include "Window.h"

Window::Window() { Setup("Window", sf::Vector2u(640, 480)); }

Window::Window(const std::string& name, const sf::Vector2u& size)
{
	Setup(name, size);
}

Window::~Window() { Destroy(); }

void Window::Setup(const std::string& name, const sf::Vector2u& size)
{
	m_windowTitle = name;
	m_windowSize = size;
	m_isFullscreen = false;
	m_isDone = false;
	m_window.setFramerateLimit(60);
	Create();
}

void Window::Create()
{
	auto Style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, Style);
}

void Window::Destroy()
{
	m_window.close();
}

void Window::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_isDone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}

void Window::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
void Window::EndDraw() { m_window.display(); }
bool Window::IsDone() { return m_isDone; }
bool Window::IsFullScreen() { return m_isFullscreen; }

sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::Draw(sf::Drawable& drawable)
{
	m_window.draw(drawable);
}