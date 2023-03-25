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

    sf::Clock clock;

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
    std::vector<Game::Block> map_player1;
    std::vector<Game::Block> map_player2;
    std::vector<Game::Block> map_player3;
    map_player1 = _map.getMap_player1();
    map_player2 = _map.getMap_player2();
    map_player3 = _map.getMap_player3();
    while (_window.isOpen()) {
        _dtime = getDtime();
        sf::Event event;
        if (clock.getElapsedTime() > sf::milliseconds(300)) {
            _player1.setDirection(Direction::NONE);
            _player2.setDirection(Direction::NONE);
            _player1.setScale({1, 1});
            _player2.setScale({1, -1});
            _player1.setPosition({850, 414});
            _player2.setPosition({850, 674});
            clock.restart();
        }
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed) {
                clock.restart();
                if (event.key.code == sf::Keyboard::Z) {
                    pressed_z = true;
                    _player1.setDirection(Direction::UP);
                }
                if (event.key.code == sf::Keyboard::Q) {
                    pressed_q = true;
                    _player1.setDirection(Direction::LEFT);
                    _player1.setScale({-1, 1});
                    _player1.setPosition({850 + _player1.getSize().x * 5, _player1.getPosition().y});
                }
                if (event.key.code == sf::Keyboard::D) {
                    pressed_d = true;
                    _player1.setDirection(Direction::RIGHT);
                    _player1.setScale({1, 1});
                    _player1.setPosition({850, 414});
                }
                if (event.key.code == sf::Keyboard::Up) {
                    pressed_up = true;
                    _player2.setDirection(Direction::UP);
                }
                if (event.key.code == sf::Keyboard::Left) {
                    pressed_left = true;
                    _player2.setDirection(Direction::LEFT);
                    _player2.setScale({-1, -1});
                    _player2.setPosition({850 + _player2.getSize().x * 5, _player2.getPosition().y});
                }
                if (event.key.code == sf::Keyboard::Right) {
                    pressed_right = true;
                    _player2.setDirection(Direction::RIGHT);
                    _player2.setScale({1, -1});
                    _player2.setPosition({850, 674});
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Z) {
                    pressed_z = false;
                    _player1.setDirection(Direction::UP);
                }
                if (event.key.code == sf::Keyboard::Q) {
                    pressed_q = false;
                    _player1.setDirection(Direction::LEFT);
                }
                if (event.key.code == sf::Keyboard::D) {
                    pressed_d = false;
                    _player1.setDirection(Direction::RIGHT);
                }
                if (event.key.code == sf::Keyboard::Up) {
                    pressed_up = false;
                    _player2.setDirection(Direction::UP);
                }
                if (event.key.code == sf::Keyboard::Left) {
                    pressed_left = false;
                    _player2.setDirection(Direction::LEFT);
                }
                if (event.key.code == sf::Keyboard::Right) {
                    pressed_right = false;
                    _player2.setDirection(Direction::RIGHT);
                }
            }
        }
        _window.clear();
        _player1.getDirection();
        _parallax_p1.update(_dtime, _player1.getDirection());
        _parallax_p2.update(_dtime, _player2.getDirection());
        _parallax_p1.draw(_window);
        _parallax_p2.draw(_window);
        //print all map block
        for (std::size_t i = 0; i < map_player1.size(); i++) {
            map_player1[i].update(_dtime, _player1.getDirection());
            map_player1[i].draw(_window);
        }
        for (std::size_t i = 0; i < map_player2.size(); i++) {
            map_player2[i].update(_dtime, Direction::NONE);
            map_player2[i].draw(_window);
        }
        for (std::size_t i = 0; i < map_player3.size(); i++) {
            map_player3[i].update(_dtime, _player2.getDirection());
            map_player3[i].draw(_window);
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
