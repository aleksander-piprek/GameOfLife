#ifndef GAME_HPP    
#define GAME_HPP

// #include <SFML/Graphics.hpp>
#include "../window/window.hpp"
#include "../rectangle/rectangle.hpp"

class Game
{
    void conway(Window& window);

    public:
        Game();
        void run();
};

#endif //GAME_HPP