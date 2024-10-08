/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Map
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Block.hpp"
#include "Player.hpp"

namespace Game {
    class Map {
        public:
            Map(std::string option);
            ~Map();
            void Parse();
            std::vector<Game::IBlock *> getMap_player1() const;
            std::vector<Game::IBlock *> getMap_floor() const;
            std::vector<Game::IBlock *> getMap_player2() const;
        protected:
        private:
            std::string _option;
            std::vector<Game::IBlock *> _map_player1;
            std::vector<Game::IBlock *> _map_floor;
            std::vector<Game::IBlock *> _map_player2;
            
    };
}

