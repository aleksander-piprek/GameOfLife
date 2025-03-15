#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>

class Rectangle
{
    public: 
        Rectangle(int gridX, int gridY);

        inline const sf::RectangleShape& getRectangle() { return rect; }
        inline sf::Vector2i getCellPositionOnGrid() { 
            int x = static_cast<int>(rect.getPosition().x / 10);
            int y = static_cast<int>(rect.getPosition().y / 10);
            return sf::Vector2i{x, y};}

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
        sf::Vector2f position;
        int neighbours = 0;        
        Rectangle::State state;
};

#endif //RECTANGLE_HPP