#ifndef GAME_HPP    
#define GAME_HPP

#include "../window/window.hpp"
#include "../cell/cell.hpp"

#include <vector>
#include <map>

class Game
{
    public:
        Game();
        void run();        

        std::vector<Cell> rectanglesVector;
        std::map<std::pair<int, int>, bool> rectanglesGridBoolMap;

    private:
        void setInitialRectangles();
        void setInitialRectanglesBoolMap();
        void conway(Window& window);

        int gridX = Window::screenWidth / 10;
        int gridY = Window::screenHeight / 10;
};

#endif //GAME_HPP