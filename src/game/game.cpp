#include "game.hpp"

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

Game::Game(const std::string& scenarioPath)
{
    setInitialCells(scenarioPath);
    setInitialCellsMap();
}

void Game::run()
{
    Window window("Game of Life");

    while(window.isOpen())
    {
        window.update();
        window.clearContents();

        conway(window);
        window.displayContents();
    }
}

void Game::conway(Window& window)
{
    // Draw cells from current generation
    for(auto& cell : cellVector)
    {
        window.setDrawableContents(cell.getRectangle());        
    }    

    sf::sleep(sf::milliseconds(20));
    generation++;
    std::cout << "Generation: " << generation << std::endl;

    // Calculate alive cells for next generation
    for(auto& cell : cellVector)
    {
        calculateConwayForAliveCells(cell);
    }

    // Calculate dead cells to be bred for next generation
    for(auto& cell : cellVector)
    {
        calculateConwayForSurroundingDeadCells(cell);
    }

    breedOrKillCells();
}

void Game::setInitialCells(const std::string& scenarioPath)
{
    std::ifstream file(scenarioPath);
    
    nlohmann::json j;
    file >> j;

    for(auto& cell : j["cells"])
    {
        cellVector.push_back(Cell(cell["x"], cell["y"]));
    }
}

void Game::setInitialCellsMap()
{
    for(int y = 0; y < gridY; y++)
    {
        for(int x = 0; x < gridX; x++)
        {
            cellGridBoolMap[{x, y}] = false;
        }
    }

    for(auto& cell : cellVector)
    {
        int x = cell.getCellPosition().x;
        int y = cell.getCellPosition().y;

        cellGridBoolMap[{x, y}] = true;
    }
}

void Game::calculateConwayForAliveCells(Cell& cell)
{
    cell.neighbours = calculateAliveCellNeighbours(cell);
    cell.state = getAliveCellState(cell);
}

void Game::calculateConwayForSurroundingDeadCells(Cell& cell)
{
    Cell newCell;
    for(int y = cell.getCellPosition().y - 1; y <= cell.getCellPosition().y + 1; y++)
    {
        for(int x = cell.getCellPosition().x - 1; x <= cell.getCellPosition().x + 1; x++)
        {
            if(!cellGridBoolMap[{x, y}])
            {
                newCell = Cell(x, y);
                calculateAliveCellNeighbours(newCell);
                if(newCell.neighbours == 3)
                {
                    newCell.state = Cell::State::Breed;
                    
                    auto it = std::find_if(cellVector.begin(), cellVector.end(), 
                        [&newCell](Cell& c) { return c.getCellPosition() == newCell.getCellPosition(); });
                    
                    if(it == cellVector.end())  
                        cellVector.push_back(newCell);

                }
            }
        }
    }

}

int Game::calculateAliveCellNeighbours(Cell& cell)
{
    cell.neighbours = 0;
    for(int y = cell.getCellPosition().y - 1; y <= cell.getCellPosition().y + 1; y++)
    {
        for(int x = cell.getCellPosition().x - 1; x <= cell.getCellPosition().x + 1; x++)
        {
            if(cellGridBoolMap[{x, y}] && !(x == cell.getCellPosition().x && y == cell.getCellPosition().y))
            {
                cell.neighbours++;
            }
        }
    }
    return cell.neighbours;
}

Cell::State Game::getAliveCellState(Cell& cell)
{
    if(cell.neighbours < 2 || cell.neighbours > 3)
    {
        return Cell::State::Kill;
    }
    else if(cell.neighbours == 2 || cell.neighbours == 3)
    {
        return Cell::State::Survive;
    }
    else
    {
        return Cell::State::Null;
    }
}

void Game::breedOrKillCells()
{
    for(auto it = cellVector.begin(); it != cellVector.end();)
    {
        switch(it->state)
        {
            case Cell::State::Survive:
                cellGridBoolMap[{it->getCellPosition().x, it->getCellPosition().y}] = true;
                it->state = Cell::State::Null;
                ++it;
                break;
            case Cell::State::Breed:
                cellGridBoolMap[{it->getCellPosition().x, it->getCellPosition().y}] = true;
                it->state = Cell::State::Null;
                ++it;
                break;
            case Cell::State::Kill:
                cellGridBoolMap[{it->getCellPosition().x, it->getCellPosition().y}] = false;
                it = cellVector.erase(it);
                break;                
            default:
                ++it;
                break;    
        }
    }
}