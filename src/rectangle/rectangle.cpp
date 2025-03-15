#include "rectangle.hpp"

#include <iostream>

Rectangle::Rectangle(int gridX, int gridY)
{
    rect.setSize(sf::Vector2f(10, 10));
    rect.setPosition(gridX * 10, gridY * 10);
    rect.setFillColor(sf::Color::Yellow);
    rect.setOutlineColor(sf::Color(75, 75, 75));
    rect.setOutlineThickness(1);
}

void Rectangle::calculateConway()
{
    neighbours = calculateCellNeighbours();
    state = getCellState(neighbours);
    setCell(state);
}

int Rectangle::calculateCellNeighbours()
{
    return neighbours;
}

Rectangle::State Rectangle::getCellState(const int& neighbours)
{
    switch(neighbours)
    {
        case 0:
            return Rectangle::State::Null;
        case 1:
            return Rectangle::State::Dead;
        case 2:
            return Rectangle::State::Alive;
        case 3:
            return Rectangle::State::Reproduce;
        case 4:
            return Rectangle::State::Overpopulated;
        default:
            return Rectangle::State::Null;
    }
}

void Rectangle::setCell(Rectangle::State state)
{
    
}