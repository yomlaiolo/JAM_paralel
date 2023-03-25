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
            std::vector<Game::Block> getMap() const;
        protected:
        private:
            std::string _option;
            std::vector<Game::Block> _map;
            
    };
}

