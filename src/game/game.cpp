#include "game.hpp"
#include <iostream>

Game::Game()
{
    setInitialRectangles();
    setInitialRectanglesBoolMap();
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
    rectanglesVector.push_back(Rectangle(3, 3));
    rectanglesVector.push_back(Rectangle(4, 3));
    rectanglesVector.push_back(Rectangle(5, 3));
}

void Game::setInitialRectanglesBoolMap()
{
    for(int y = 0; y < gridY; y++)
    {
        for(int x = 0; x < gridX; x++)
        {
            rectanglesGridBoolMap[{x, y}] = false;
        }
    }

    for(auto& rectangle : rectanglesVector)
    {
        int x = rectangle.getCellPositionOnGrid().x;
        int y = rectangle.getCellPositionOnGrid().y;

        rectanglesGridBoolMap[{x, y}] = true;
    }
}