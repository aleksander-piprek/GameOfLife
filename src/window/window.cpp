#include "window.hpp"

Window::Window(const std::string& windowName)
    : window(sf::VideoMode(800, 600), 
      windowName, 
      sf::Style::Titlebar)
{
    window.setVerticalSyncEnabled(true);
}

void Window::update()
{
    sf::Event event;
    if(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
        {
            window.close();
        }
    }
}

void Window::clearContents()
{
    window.clear(sf::Color::Black);
}

void Window::setDrawableContents(const sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::displayContents()
{
    window.display();   
}