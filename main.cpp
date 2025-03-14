#include "src/window/window.hpp"
#include "src/rectangle/rectangle.hpp"

int main()
{
    Window window("Game of Life");

    while(window.isOpen())
    {
        window.update();
        window.clearContents();

        for(int i=0; i<10; i++)
        {
            Rectangle rect(10*i, 10*i, 10, 10);
            window.setDrawableContents(rect.getRectangle());
        }

        window.displayContents();
    }

    return 0;
}