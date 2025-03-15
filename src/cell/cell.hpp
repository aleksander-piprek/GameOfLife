#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>

class Cell
{
    public: 
        Cell(int gridX, int gridY);

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
        Cell::State getCellState(const int& neighbours);
        void setCell(Cell::State state);        

        sf::RectangleShape rect;
        sf::Vector2f position;
        int neighbours = 0;        
        Cell::State state;
};

#endif //CELL_HPP
