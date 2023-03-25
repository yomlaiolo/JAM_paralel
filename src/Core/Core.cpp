/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Core
*/

#include "Core.hpp"

Game::Core::Core(std::string option) : _parallax(), _player1("assets/player1.png"), _player2("assets/player2.png"), _map("test.txt"), _window(sf::VideoMode(1920, 1080), "JAM_paralel"), _clock(), _time()
{
    _dtime = 0;
    _clock.restart();
    _time = _clock.getElapsedTime();
    _map.Parse();
}

Game::Core::~Core()
{

}

void Game::Core::Run()
{
    while (_window.isOpen()) {
        _dtime = getDtime();
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        _parallax.update(_window, _dtime);
        _window.display();
    }
}

float Game::Core::getDtime()
{
    static float old = 0;
    float time = _clock.getElapsedTime().asSeconds();
    float dtime = time - old;
    old = time;
    return dtime;
}
