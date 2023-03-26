/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Map
*/

#include "Map.hpp"
#include "Block.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Game::Map::Map(std::string option)
{
    _option = option;
}

Game::Map::~Map()
{
    for (auto &i : _map_player1)
        delete i;
    for (auto &i : _map_floor)
        delete i;
    for (auto &i : _map_player2)
        delete i;
}

void Game::Map::Parse()
{
    std::ifstream file(_option);
    std::string line;
    int y = 0;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            for (int i = 0; i < (int)line.length(); i++) {
                if (line[i] == '#') {
                    if (y < 8)
                        _map_player1.push_back(new Game::Block("assets/block.png", {(float)(i * 64), (float)(y * 64)}, {64, 64}));
                    else if (y == 8) 
                        _map_floor.push_back(new Game::Block("assets/block.png", {(float)(i * 64), (float)(y * 64)}, {64, 64}));
                    else
                        _map_player2.push_back(new Game::Block("assets/block.png", {(float)(i * 64), (float)(y * 64)}, {64, 64}));
                }
            }
            y += 1;
        }
        file.close();
        if (y == 0) {
            std::cout << "Map is empty" << std::endl;
            exit(84);
        }
        if (y != 17) {
            std::cout << "Map don't have 17 lines" << std::endl;
            exit(84);
        }
    } else {
        std::cout << "Unable to open file" << std::endl;
        exit(84);
    }
}

std::vector<Game::IBlock *> Game::Map::getMap_player1() const
{
    return _map_player1;
}

std::vector<Game::IBlock *> Game::Map::getMap_floor() const
{
    return _map_floor;
}

std::vector<Game::IBlock *> Game::Map::getMap_player2() const
{
    return _map_player2;
}
