/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Core
*/

#include "Core.hpp"

Game::Core::Core(std::string option) : _player1("assets/player1.png", {850, 414}), _player2("assets/player2.png", {850, 674}), _map(option), _window(sf::VideoMode(1920, 1080), "JAM_paralel")
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
    std::vector<Game::Block *> map_player1;
    std::vector<Game::Block *> map_floor;
    std::vector<Game::Block *> map_player2;
    map_player1 = _map.getMap_player1();
    map_floor = _map.getMap_floor();
    map_player2 = _map.getMap_player2();
    //IMPORTANT NE PAS SUPPRIMER LES STD::COUT
    //std::cout << "player 1:" << std::endl << _player1.getPosition().x << " " << _player1.getPosition().y << std::endl;
    //for (auto &i : map_player1) {
    //    std::cout << "x: " << i.getCoords().x << " y: " << i.getCoords().y << std::endl;
    //}
    //std::cout << "sol:" << std::endl;
    //for (auto &i : map_player2) {
    //    std::cout << "x: " << i.getCoords().x << " y: " << i.getCoords().y << std::endl;
    //}
    //std::cout << "player 2:" << std::endl << _player2.getPosition().x << " " << _player2.getPosition().y << std::endl;
    //for (auto &i : map_player3) {
    //    std::cout << "x: " << i.getCoords().x << " y: " << i.getCoords().y << std::endl;
    //}
    while (_window.isOpen()) {
        _dtime = getDtime();
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed) {
                clock.restart();
                switch (event.key.code) {
                    case sf::Keyboard::Z:
                        _pressed_z = true;
                        _player1.setDirection(Direction::UP);
                        break;
                    case sf::Keyboard::Q:
                        _pressed_q = true;
                        _player1.setDirection(Direction::LEFT);
                        _player1.setScale({-1, 1});
                        _player1.setPosition({850 + _player1.getSize().x, _player1.getPosition().y});
                        break;
                    case sf::Keyboard::D:
                        _pressed_d = true;
                        _player1.setDirection(Direction::RIGHT);
                        _player1.setScale({1, 1});
                        _player1.setPosition({850, 414});
                        break;
                    case sf::Keyboard::Up:
                        _pressed_up = true;
                        _player2.setDirection(Direction::UP);
                        break;
                    case sf::Keyboard::Left:
                        _pressed_left = true;
                        _player2.setDirection(Direction::LEFT);
                        _player2.setScale({-1, -1});
                        _player2.setPosition({850 + _player2.getSize().x, _player2.getPosition().y});
                        break;
                    case sf::Keyboard::Right:
                        _pressed_right = true;
                        _player2.setDirection(Direction::RIGHT);
                        _player2.setScale({1, -1});
                        _player2.setPosition({850, 674});
                        break;
                    default:
                        break;
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                    case sf::Keyboard::Z:
                        _pressed_z = false;
                        _player1.setDirection(Direction::NONE);
                        break;
                    case sf::Keyboard::Q:
                        _pressed_q = false;
                        _player1.setDirection(Direction::NONE);
                        break;
                    case sf::Keyboard::D:
                        _pressed_d = false;
                        _player1.setDirection(Direction::NONE);
                        break;
                    case sf::Keyboard::Up:
                        _pressed_up = false;
                        _player2.setDirection(Direction::NONE);
                        break;
                    case sf::Keyboard::Left:
                        _pressed_left = false;
                        _player2.setDirection(Direction::NONE);
                        break;
                    case sf::Keyboard::Right:
                        _pressed_right = false;
                        _player2.setDirection(Direction::NONE);
                        break;
                    default:
                        break;
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
    for (auto &i : map_player1) {
        i->update(_dtime, _player1.getDirection());
        i->draw(_window);
    }
    for (auto &i : map_floor) {
        i->update(_dtime, Direction::NONE);
        i->draw(_window);
    }
    for (auto &i : map_player2) {
        i->update(_dtime, _player2.getDirection());
        i->draw(_window);
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
