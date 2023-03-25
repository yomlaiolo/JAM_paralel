/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Core
*/

#pragma once

#include "Parallax.hpp"
#include "Player.hpp"
#include "Map.hpp"

#include <iostream>

namespace Game {
    class Core {
    public:
        Core(std::string option);
        ~Core();
        void Run();
        float getDtime();
    protected:
    private:
        Parallax _parallax;
        Player _player1;
        Player _player2;
        Map _map;
        sf::RenderWindow _window;
        sf::Clock _clock;
        sf::Time _time;
        float _dtime;
};
}
