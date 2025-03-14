#include "game.hpp"

int currentPositionX = 0;
int currentPositionY = 0;

int maxPositionX = 790;
int maxPositionY = 590;

Game::Game()
{
}

void Game::run()
{
    Window window("Game of Life");

    while(window.isOpen())
    {
        window.update();
        window.clearContents();

        conway(window);

        window.displayContents();
    }
}

void Game::conway(Window& window)
{
    Rectangle rect(currentPositionX, currentPositionY, 10, 10);
    if(currentPositionX >= maxPositionX)
    {
        currentPositionX = 0;
        currentPositionY+=10;    
    }
    
    window.setDrawableContents(rect.getRectangle());
    sf::sleep(sf::milliseconds(10));
    currentPositionX+=10;
}