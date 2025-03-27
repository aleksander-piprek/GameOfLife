#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>

class Cell
{
    public: 
        Cell() = default;
        Cell(const uint& gridX, const uint& gridY)
        {
            rect.setSize(sf::Vector2f(10, 10));
            rect.setPosition(gridX * 10, (gridY * 10) + Window::windowHeightOffset);
            rect.setFillColor(sf::Color::Yellow);
            rect.setOutlineColor(sf::Color(75, 75, 75));
            rect.setOutlineThickness(1);
            state = State::Null;
            positionX = gridX;
            positionY = gridY;
        }

        inline const sf::RectangleShape& getRectangle() { return rect; }
        inline const sf::Vector2i getCellPosition() { 
            int x = static_cast<int>(rect.getPosition().x / 10);
            int y = static_cast<int>(rect.getPosition().y / 10)
                  - Window::windowHeightOffset / 10;
            return sf::Vector2i{x, y};}

        uint neighbours = 0;        
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