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
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        {
            bool paused = true;
            while (paused)
            {
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                    {
                        paused = false;
                    }
                    else if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                    {
                        window.close();
                        paused = false;
                    }
                }
            }
        }
    }
}

void Window::clearContents()
{
    window.clear(sf::Color::Black);
    addGrid();
}

void Window::setDrawableContents(const sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::displayContents()
{
    window.display();   
}

void Window::addGrid()
{
    sf::Color color(100, 100, 100);
    for(int x = 0; x < screenWidth; x += 10)
    {
        sf::RectangleShape line(sf::Vector2f(1, screenWidth));
        line.setPosition(x, 0);
        line.setFillColor(color);
        window.draw(line);
    }

    for(int y = 0; y < screenHeight; y += 10)
    {
        sf::RectangleShape line(sf::Vector2f(screenWidth, 1));
        line.setPosition(0, y);
        line.setFillColor(color);
        window.draw(line);
    }
}