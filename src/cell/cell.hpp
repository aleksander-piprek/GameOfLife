#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>

class Cell
{
    public: 
        Cell() = default;
        Cell(int gridX, int gridY)
        {
            rect.setSize(sf::Vector2f(10, 10));
            rect.setPosition(gridX * 10, gridY * 10);
            positionX = gridX;
            positionY = gridY;  
            rect.setFillColor(sf::Color::Yellow);
            rect.setOutlineColor(sf::Color(75, 75, 75));
            rect.setOutlineThickness(1);
            state = State::Null;
        }

        inline const sf::RectangleShape& getRectangle() { return rect; }
        inline sf::Vector2i getCellPosition() { 
            int x = static_cast<int>(rect.getPosition().x / 10);
            int y = static_cast<int>(rect.getPosition().y / 10);
            return sf::Vector2i{x, y};}

        int neighbours = 0;        
        enum class State
        {
            Null,
            Kill,
            Survive,
            Breed
        } state;  
        
    private:  
        sf::RectangleShape rect;
        uint positionX;
        uint positionY;
};

#endif //CELL_HPP
