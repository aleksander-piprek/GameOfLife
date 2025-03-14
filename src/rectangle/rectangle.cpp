#include "rectangle.hpp"

Rectangle::Rectangle(int X, int Y, int Width, int Height)
{
    rect.setSize(sf::Vector2f(Width, Height));
    rect.setPosition(X, Y);
}

int Rectangle::calculateCellNeighbours()
{
    neighbours = 0;
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

void Rectangle::setCell()
{
    
}