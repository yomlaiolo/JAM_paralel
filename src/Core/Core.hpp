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
        Parallax _parallax_p1;
        Parallax _parallax_p2;
        Player _player1;
        Player _player2;
        Map _map;
        sf::RenderWindow _window;
        sf::Clock _clock;
        sf::Time _time;
        float _dtime;

        bool pressed_z = false;
        bool pressed_q = false;
        bool pressed_d = false;
    
        bool pressed_up = false;
        bool pressed_left = false;
        bool pressed_right = false;

};
}
