#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

class Window
{ 
    public:
        Window(const std::string& windowName);

        void update();
        void clearContents();
        void setDrawableContents(const sf::Drawable& drawable);
        void displayContents();

        inline const bool isOpen() { return window.isOpen(); } 

        // 1 is added to the widths so that the grid is visible on the bottom and right edges (purely cosmetic purpose)
        static const int screenWidth = 1281;
        static const int screenHeight = 721;    

    private:
        void addGrid();

        sf::RenderWindow window;
};

#endif