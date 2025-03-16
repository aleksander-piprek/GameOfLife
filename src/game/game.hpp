#ifndef GAME_HPP    
#define GAME_HPP

#include "../window/window.hpp"
#include "../cell/cell.hpp"

#include <vector>
#include <map>
#include <string>

class Game
{
    public:
        Game(const std::string& scenarioPath);
        void run();        

    private:
        void setInitialCells(const std::string& scenarioPath);
        void setInitialCellsMap();
        void conway(Window& window);

        void calculateConwayForAliveCells(Cell& cell);
        void calculateConwayForSurroundingDeadCells(Cell& cell);
        void breedOrKillCells();
        
        int calculateAliveCellNeighbours(Cell& cell);
        Cell::State getAliveCellState(Cell& cell);

        std::vector<Cell> cellVector;
        std::map<std::pair<int, int>, bool> cellGridBoolMap;
        int gridX = Window::screenWidth / 10;
        int gridY = Window::screenHeight / 10;
        uint generation = 0;
};

#endif //GAME_HPP