#include "cell.hpp"

#include <iostream>

Cell::Cell(int gridX, int gridY)
{
    rect.setSize(sf::Vector2f(10, 10));
    rect.setPosition(gridX * 10, gridY * 10);
    rect.setFillColor(sf::Color::Yellow);
    rect.setOutlineColor(sf::Color(75, 75, 75));
    rect.setOutlineThickness(1);
}

void Cell::calculateConway()
{
    neighbours = calculateCellNeighbours();
    state = getCellState(neighbours);
    setCell(state);
}

int Cell::calculateCellNeighbours()
{
    return neighbours;
}

Cell::State Cell::getCellState(const int& neighbours)
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

void Cell::setCell(Cell::State state)
{
    
}
