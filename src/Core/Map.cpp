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
    std::cout << "Parsing map" << std::endl;

    std::ifstream file(_option);
    std::string line;
    int y = 0;
    std::vector<std::vector<Game::Block>> map;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
            std::vector<Game::Block> lineMap;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == '#') {
                    lineMap.push_back(Game::Block("assets/block.png", std::make_pair(i * 32, y * 32), std::make_pair(64, 64)));
                }
            }
            map.push_back(lineMap);
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
    }
}

std::vector<Game::Block> Game::Map::getMap() const
{
    return _map;
}