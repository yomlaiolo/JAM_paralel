/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Block
*/

#include "Block.hpp"

Game::Block::Block(const std::string &texture, const std::pair<int, int> &coords, const std::pair<int, int> &size)
{
    _sprite = sf::Sprite();
    _texture = sf::Texture();
    _coords.x = coords.first;
    _coords.y = coords.second;
    _size = size;
    _texture.loadFromFile(texture);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, _size.first, _size.second));
    _isSolid = false;
    _isEvent = false;
    _event = Game::Event::NO;
    _sprite.setPosition(_coords);
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
    _coords.x = coords.first;
    _coords.y = coords.second;
    _sprite.setPosition(_coords);
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
    _sprite.setPosition(_coords.x, _coords.y);
}

sf::Vector2f Game::Block::getCoords() const
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

void Game::Block::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
}

void Game::Block::update(float deltaTime, Game::Direction direction)
{
    std::pair<int, int> coords;
    coords.first = getCoords().x;
    if (direction == Game::Direction::LEFT)
        coords.first = getCoords().x + 280 * deltaTime;
    if (direction == Game::Direction::RIGHT)
        coords.first = getCoords().x - 280 * deltaTime;
    coords.second = getCoords().y;
    setCoords(coords);
}
