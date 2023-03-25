/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Core
*/

#include "Core.hpp"

Game::Core::Core(std::string option) : _parallax_p1(), _parallax_p2(), _player1("assets/player1.png", {850, 414}), _player2("assets/player2.png", {850, 674}), _map(option), _window(sf::VideoMode(1920, 1080), "JAM_paralel"), _clock(), _time()
{
    _map.Parse();
    _dtime = 0;
    _clock.restart();
    _time = _clock.getElapsedTime();
}

Game::Core::~Core()
{

}

static void add_layer(Game::Parallax &parallax, std::string path, float speed, int x, int y, bool flip = false, bool reverse = false)
{
    sf::Sprite *sprite = new sf::Sprite();
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(path);
    sprite->setTexture(*texture);
    if (flip)
        sprite->setScale(sf::Vector2f(1, -1));
    if (reverse) {
        sprite->setScale(sf::Vector2f(-1, 1));
    }
    sprite->setPosition(x, y);
    parallax.addLayer(*sprite, speed);
}

void Game::Core::Run()
{
    add_layer(_parallax_p1, "assets/Parallax1-1.png", 0.8, 0, 0);
    add_layer(_parallax_p1, "assets/Parallax1-1.png", 0.8, 1920, 0);
    add_layer(_parallax_p1, "assets/Parallax1-2.png", 1.8, 0, 0);
    add_layer(_parallax_p1, "assets/Parallax1-2.png", 1.8, 1920, 0);
    add_layer(_parallax_p1, "assets/Parallax1-3.png", 2.8, 0, 0);
    add_layer(_parallax_p1, "assets/Parallax1-3.png", 2.8, 1920, 0);

    add_layer(_parallax_p2, "assets/Parallax1-1.png", 0.8, 0, 1080, true);
    add_layer(_parallax_p2, "assets/Parallax1-1.png", 0.8, 1920, 1080, true);
    add_layer(_parallax_p2, "assets/Parallax1-2.png", 1.8, 0, 1080, true);
    add_layer(_parallax_p2, "assets/Parallax1-2.png", 1.8, 1920, 1080, true);
    add_layer(_parallax_p2, "assets/Parallax1-3.png", 2.8, 0, 1080, true);
    add_layer(_parallax_p2, "assets/Parallax1-3.png", 2.8, 1920, 1080, true);

    _window.setFramerateLimit(60);
    _player2.setScale({1, -1});
    std::vector<Game::Block> map;
    map = _map.getMap();
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
        _player1.getDirection();
        //_parallax_p1.update(_window, _dtime, _player1.getDirection());
        //_parallax_p2.update(_window, _dtime, _player2.getDirection());
        _parallax_p1.update(_dtime, Direction::RIGHT);
        _parallax_p2.update(_dtime, Direction::LEFT);
        _parallax_p1.draw(_window);
        _parallax_p2.draw(_window);
        for (auto &block : map) {
            block.update(_dtime, Direction::RIGHT);
            block.draw(_window);
        }
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
