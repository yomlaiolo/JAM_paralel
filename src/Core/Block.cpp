/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Block
*/

#include "Block.hpp"

Game::Block::Block(const std::string &texture, const std::pair<int, int> &coords, const std::pair<int, int> &size) : _sprite(), _texture()
{
    _coords = coords;
    _size = size;
    _texture.loadFromFile(texture);
    _sprite.setTexture(_texture);
    _isSolid = false;
    _isEvent = false;
    _event = Game::Event::NONE;
}

Game::Block::~Block()
{
}

void Game::Block::setTexture(const std::string &texture)
{
    _texture.loadFromFile(texture);
}

void Game::Block::setCoords(const std::pair <int, int> &coords)
{
    _coords = coords;
}

void Game::Block::setSize(const std::pair <int, int> &size)
{
    _size = size;
}

void Game::Block::setSolid(bool isSolid)
{
    _isSolid = isSolid;
}

void Game::Block::setEvent(const Game::Event &event)
{
    _event = event;
}

void Game::Block::setSprite()
{
    _sprite.setTexture(_texture);
    _sprite.setPosition(_coords.first, _coords.second);
}

std::pair<int, int> Game::Block::getCoords() const
{
    return _coords;
}

std::pair<int, int> Game::Block::getSize() const
{
    return _size;
}

sf::Sprite Game::Block::getSprite() const
{
    return _sprite;
}

sf::Texture Game::Block::getTexture() const
{
    return _texture;
}

bool Game::Block::isSolid() const
{
    return _isSolid;
}

bool Game::Block::isEvent() const
{
    return _isEvent;
}

Game::Event Game::Block::getEvent() const
{
    return _event;
}

