/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Player
*/

#include "Player.hpp"

Game::Player::Player()
{
    _sprite = sf::Sprite();
    _position = std::pair<int, int>(0, 0);
    _size = std::pair<int, int>(0, 0);
    _speed = 0;
    _direction = Direction::NONE;
}

Game::Player::~Player()
{

}

void Game::Player::move(Direction direction)
{
    if (direction == Direction::UP)
        _position.second -= _speed;
    if (direction == Direction::DOWN)
        _position.second += _speed;
    if (direction == Direction::LEFT)
        _position.first -= _speed;
    if (direction == Direction::RIGHT)
        _position.first += _speed;
}

void Game::Player::update()
{

}

void Game::Player::draw(sf::RenderWindow &window)
{

}

void Game::Player::setPosition(std::pair<int, int> position)
{
    _position.first = position.first;
    _position.second = position.second;
}

void Game::Player::setSize(std::pair<int, int> size)
{
    _size.first = size.first;
    _size.second = size.second;
}

void Game::Player::setSpeed(int speed)
{
    _speed = speed;
}

void Game::Player::setDirection(Direction direction)
{
    _direction = direction;
}

std::pair<int, int> Game::Player::getPosition()
{
    return _position;
}

std::pair<int, int> Game::Player::getSize()
{
    return _size;
}

int Game::Player::getSpeed()
{
    return _speed;
}

Game::Direction Game::Player::getDirection()
{
    return _direction;
}