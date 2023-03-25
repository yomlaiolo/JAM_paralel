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
}

void Game::Map::Parse()
{
    std::ifstream file(_option);
    std::string line;
    int y = 0;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
            for (int i = 0; i < (int)line.length(); i++) {
                if (line[i] == '#') {
                    _map.push_back(Game::Block("assets/block.png", std::make_pair(i * 64, y * 64), std::make_pair(64, 64)));
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

std::vector<Game::Block> Game::Map::getMap() const
{
    return _map;
}
