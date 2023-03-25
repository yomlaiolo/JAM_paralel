/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Core
*/

#pragma once

#include <iostream>

namespace Game {
    class Core {
    public:
        Core(std::string option);
        ~Core();
        void Run();
    protected:
    private:
        Parallax _parallax;
        std::pair<Player, Player> _players;
        Map _map;
};
}
