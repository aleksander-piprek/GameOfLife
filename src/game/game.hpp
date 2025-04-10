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
        void conway();
        void updateGameInfo(Window& window);

        uint calculateAliveCellNeighbours(Cell& cell);
        Cell::State getAliveCellState(Cell& cell);
        void calculateConwayForSurroundingDeadCells(Cell& cell);
        void breedOrKillCells();
        
        std::vector<Cell> cellVector;
        std::map<std::pair<int, int>, bool> cellGridBoolMap;

        const uint gridXSize = Window::screenWidth / 10;
        const uint gridYSize = Window::screenHeight / 10;

        uint generation = 0;
        uint averageFPS = 0;
        uint totalFPS = 0;
};

#endif //GAME_HPP