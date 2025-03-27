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
        void setGameInformation(const uint& generation, const uint& averageFPS);

        inline void restartClock()          { clock.restart(); }
        inline const sf::Clock getClock()   { return clock; }

        inline const bool isOpen()          { return window.isOpen(); } 
        static const int windowHeightOffset = 20;
        
        // 1 is added to the widths so that the grid is visible on the bottom and right edges (purely cosmetic purpose)
        static const int screenWidth = 1281;
        static const int screenHeight = 721 + windowHeightOffset;

    private:
        void addGrid();
        void addFPSAndGenerationText();

        sf::RenderWindow window;
        sf::Clock clock;

        uint generation = 0;
        uint averageFPS = 0;
};

#endif