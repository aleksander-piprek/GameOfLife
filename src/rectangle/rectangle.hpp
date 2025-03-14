#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>

class Rectangle
{
    public: 
        Rectangle(int X, int Y, int Width, int Height);

        inline const sf::RectangleShape& getRectangle() { return rect; }

        enum class State
        {
            Null,
            Dead,
            Alive,
            Overpopulated,
            Reproduce
        };  

    private:
        sf::RectangleShape rect;
        int neighbours = 0;

        int calculateCellNeighbours();
        State getCellState(const int& neighbours);
        void setCell();
};

#endif //RECTANGLE_HPP