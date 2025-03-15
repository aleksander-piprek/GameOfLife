#ifndef GAME_HPP    
#define GAME_HPP

#include "../window/window.hpp"
#include "../rectangle/rectangle.hpp"

#include <vector>

class Game
{
    public:
        Game();
        void run();        

        std::vector<Rectangle> rectanglesVector;

    private:
        void setInitialRectangles();
        void conway(Window& window);
};

#endif //GAME_HPP