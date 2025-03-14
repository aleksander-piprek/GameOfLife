#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>

class Rectangle
{
    sf::RectangleShape rect;
    public: 
        Rectangle(int X, int Y, int Width, int Height);

        inline const sf::RectangleShape& getRectangle() { return rect; }
};

#endif //RECTANGLE_HPP