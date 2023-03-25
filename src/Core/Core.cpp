/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Core
*/

#include "Core.hpp"

Game::Core::Core(std::string option) : _parallax(), _player1("assets/player1.png", {850, 368}), _player2("assets/player2.png", {850, 710}), _map(option), _window(sf::VideoMode(1920, 1080), "JAM_paralel"), _clock(), _time()
{
    _dtime = 0;
    _clock.restart();
    _time = _clock.getElapsedTime();
}

Game::Core::~Core()
{

}

void Game::Core::Run()
{
    _player2.setScale({1, -1});
    while (_window.isOpen()) {
        _dtime = getDtime();
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window.close();
                return;
            }
        }
        _window.clear();
        _parallax.update(_window, _dtime);
        _player1.update(_dtime);
        _player2.update(_dtime);
        _player1.draw(_window);
        _player2.draw(_window);
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
