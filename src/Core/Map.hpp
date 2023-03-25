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

namespace Game {
    class Map {
        public:
            Map(std::string option);
            ~Map();
            Parse();
        protected:
        private:
            std::string _option;
            std::vector<std::vector<Game::Block>> _map;
            
    };
}

