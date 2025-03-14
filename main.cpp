#include "src/window/window.hpp"

int main()
{
    Window window("Game of Life");

    while(window.isOpen())
    {
        window.update();
        window.beginDraw();
        // Draw here
        window.endDraw();
    }

    return 0;
}