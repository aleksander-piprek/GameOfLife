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

        std::vector<Cell> cellVector;
        std::map<std::pair<int, int>, bool> cellGridBoolMap;

    private:
        void setInitialCells();
        void setInitialCellsMap();
        void conway(Window& window);
        void calculateConway(Cell& cell);
        int calculateCellNeighbours(Cell& cell);
        Cell::State getCellState(const int& neighbours);
        void setCell(Cell::State state);              

        int gridX = Window::screenWidth / 10;
        int gridY = Window::screenHeight / 10;
};

#endif //GAME_HPP