#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "../window/window.hpp"

class Rectangle
{
    public: 
        Rectangle(int X, int Y, int Width, int Height);

        inline const sf::RectangleShape& getRectangle() { return rect; }

        void calculateConway();
        enum class State
        {
            Null,
            Dead,
            Alive,
            Overpopulated,
            Reproduce
        };  

    private:
        int calculateCellNeighbours();
        Rectangle::State getCellState(const int& neighbours);
        void setCell(Rectangle::State state);        

        sf::RectangleShape rect;
        int neighbours = 0;        
        Rectangle::State state;
};

#endif //RECTANGLE_HPP