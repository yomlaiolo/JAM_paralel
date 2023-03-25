/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Block
*/

#include "Block.hpp"

Game::Block::Block(const std::string &texture, const sf::Vector2f &coords, const sf::Vector2f &size)
{
    _sprite = sf::Sprite();
    _texture = sf::Texture();
    _coords = coords;
    _size = size;
    _texture.loadFromFile(texture);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, _size.x, _size.y));
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

void Game::Block::setCoords(const sf::Vector2f &coords)
{
    _coords.x = coords.x;
    _coords.y = coords.y;
    _sprite.setPosition(_coords);
}

void Game::Block::setSize(const sf::Vector2f &size)
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

sf::Vector2f Game::Block::getSize() const
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
    sf::Vector2f coords;
    coords.x = getCoords().x;
    if (direction == Game::Direction::LEFT)
        coords.x = getCoords().x + 280 * deltaTime;
    if (direction == Game::Direction::RIGHT)
        coords.x = getCoords().x - 280 * deltaTime;
    coords.y = getCoords().y;
    setCoords(coords);
}
