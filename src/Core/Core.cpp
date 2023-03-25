/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Core
*/

#include "Core.hpp"

Game::Core::Core(std::string option)
{
    _player = new Player();
    _map = new Map(option);
    _parallax = new Parallax();
}

Game::Core::~Core()
{

}

void Game::Core::Run()
{

}