#include "game.hpp"
#include <iostream>

Game::Game()
{
    setInitialCells();
    setInitialCellsMap();
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
    for(auto& cell : cellVector)
    {
        calculateConway(cell);

        window.setDrawableContents(cell.getRectangle());
    }    
}

void Game::setInitialCells()
{
    cellVector.push_back(Cell(3, 3));
    cellVector.push_back(Cell(4, 3));
    cellVector.push_back(Cell(5, 3));
}

void Game::setInitialCellsMap()
{
    for(int y = 0; y < gridY; y++)
    {
        for(int x = 0; x < gridX; x++)
        {
            cellGridBoolMap[{x, y}] = false;
        }
    }

    for(auto& cell : cellVector)
    {
        int x = cell.getCellPosition().x;
        int y = cell.getCellPosition().y;

        cellGridBoolMap[{x, y}] = true;
    }
}

void Game::calculateConway(Cell& cell)
{
    cell.neighbours = calculateCellNeighbours(cell);
    cell.state = getCellState(cell.neighbours);
    setCell(cell.state);
}

int Game::calculateCellNeighbours(Cell& cell)
{
    std::cout << "Position: " << cell.getCellPosition().x << ", " << cell.getCellPosition().y << std::endl;

    return cell.neighbours;
}

Cell::State Game::getCellState(const int& neighbours)
{
    switch(neighbours)
    {
        case 0:
            return Cell::State::Null;
        case 1:
            return Cell::State::Dead;
        case 2:
            return Cell::State::Alive;
        case 3:
            return Cell::State::Reproduce;
        case 4:
            return Cell::State::Overpopulated;
        default:
            return Cell::State::Null;
    }
}

void Game::setCell(Cell::State state)
{
    
}
