#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

class Window
{
    sf::RenderWindow window;
    const int screenWidth = 800;
    const int screenHeight = 600;    
 
    public:
        Window(const std::string& windowName);

        void update();
        void clearContents();
        void setDrawableContents(const sf::Drawable& drawable);
        void displayContents();

        inline const bool isOpen() { return window.isOpen(); } 

};

#endif