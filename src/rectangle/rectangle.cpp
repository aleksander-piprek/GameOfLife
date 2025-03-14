#include "rectangle.hpp"

Rectangle::Rectangle(int X, int Y, int Width, int Height)
{
    rect.setSize(sf::Vector2f(Width, Height));
    rect.setPosition(X, Y);
}