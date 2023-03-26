/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Parallax
*/

#include "Parallax.hpp"

Game::Parallax::Parallax()
{
}

Game::Parallax::~Parallax()
{

}

void Game::Parallax::addLayer(sf::Sprite sprite, float speed)
{
    _sprites.push_back(sprite);
    _speeds.push_back(speed);
}

void Game::Parallax::update(float deltaTime, Game::Direction direction)
{
    float x;
    for (std::size_t i = 0; i < _sprites.size(); i++) {
        x = _sprites[i].getPosition().x;
        if (direction == Direction::RIGHT)
            x = _sprites[i].getPosition().x - _speeds[i] * 100 * deltaTime;
        if (direction == Direction::LEFT)
            x = _sprites[i].getPosition().x + _speeds[i] * 100 * deltaTime;
        _sprites[i].setPosition(x, _sprites[i].getPosition().y);
        if (_sprites[i].getPosition().x < -1920)
            _sprites[i].setPosition(1915, _sprites[i].getPosition().y);
        if (_sprites[i].getPosition().x > 1920)
            _sprites[i].setPosition(-1860, _sprites[i].getPosition().y);
    }
}

void Game::Parallax::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < (int)_sprites.size(); i++) {
        window.draw(_sprites[i]);
    }
}
