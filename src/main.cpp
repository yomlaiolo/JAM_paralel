/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    Game::Core core(av[1]);
    core.Run();
    return 0;
}
