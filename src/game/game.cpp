#include "game.hpp"
#include <iostream>

int currentPositionX = 0;
int currentPositionY = 0;

int maxPositionX = Window::screenWidth - 10;
int maxPositionY = Window::screenHeight - 10;

Game::Game()
{
    setInitialRectangles();
}

void Game::run()
{
    Window window("Game of Life");

    while(window.isOpen())
    {
        window.update();
        window.clearContents();

        conway(window);
        window.displayContents();
    }
}

void Game::conway(Window& window)
{
    for(auto& rectangle : rectanglesVector)
    {
        rectangle.calculateConway();

        window.setDrawableContents(rectangle.getRectangle());
    }    
}

void Game::setInitialRectangles()
{
    rectanglesVector.push_back(Rectangle(100, 100, 10, 10));
    rectanglesVector.push_back(Rectangle(110, 100, 10, 10));
    rectanglesVector.push_back(Rectangle(120, 100, 10, 10));
}