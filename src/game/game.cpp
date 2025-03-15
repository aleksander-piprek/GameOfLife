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
    for(auto& cell : rectanglesVector)
    {
        cell.calculateConway();

        window.setDrawableContents(cell.getRectangle());
    }    
}

void Game::setInitialRectangles()
{
    rectanglesVector.push_back(Cell(3, 3));
    rectanglesVector.push_back(Cell(4, 3));
    rectanglesVector.push_back(Cell(5, 3));
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

    for(auto& cell : rectanglesVector)
    {
        int x = cell.getCellPositionOnGrid().x;
        int y = cell.getCellPositionOnGrid().y;

        rectanglesGridBoolMap[{x, y}] = true;
    }
}