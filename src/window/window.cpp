#include "window.hpp"
#include <iostream>
Window::Window(const std::string& windowName)
    : window(sf::VideoMode((uint)screenWidth, (uint)screenHeight), windowName, sf::Style::Titlebar)
{
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
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
}

void Window::setDrawableContents(const sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::displayContents()
{
    addGrid();
    addFPSAndGenerationText();
    window.display();   
}

void Window::addGrid()
{
    sf::Color color(75, 75, 75);
    for(int x = 0; x < screenWidth; x += 10)
    {
        sf::RectangleShape line(sf::Vector2f(1, screenHeight));
        line.setPosition(x, windowHeightOffset);
        line.setFillColor(color);
        window.draw(line);
    }

    for(int y = windowHeightOffset; y < screenHeight; y += 10)
    {
        sf::RectangleShape line(sf::Vector2f(screenWidth, 1));
        line.setPosition(0, y);
        line.setFillColor(color);
        window.draw(line);
    }
}

void Window::addFPSAndGenerationText()
{
    sf::Font font;
    font.loadFromFile("../assets/font.otb");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);

    text.setPosition(5, 0);
    text.setString("FPS: " + std::to_string((int)averageFPS));
    window.draw(text);

    text.setPosition(100, 0);
    text.setString("Generation: " + std::to_string(generation));
    window.draw(text);
}

void Window::setGameInformation(const uint& generation, const uint& averageFPS)
{
    this->generation = generation;
    this->averageFPS = averageFPS;
}