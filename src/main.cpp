/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** main
*/

#include "Core.hpp"
#include <string.h>
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2 || ac > 4)
        return 84;
    Game::Core core(av[1]);
    if (ac == 3 && strcmp(av[2],"-getaway") == 0) {
        std::cout << "GET AWAY" << std::endl;
        core.Run("GetAway.ogg"); 
    }
    else
        core.Run("music.ogg");
    return 0;
}
