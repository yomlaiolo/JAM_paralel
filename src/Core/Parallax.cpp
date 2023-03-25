/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Parallax
*/

#include "Parallax.hpp"

Game::Parallax::Parallax()
{
    _sprites = std::vector<sf::Sprite>();
    _textures = std::vector<sf::Texture>();
    _positions = std::vector<std::pair<int, int>>();
    _speeds = std::vector<float>();
}

Game::Parallax::~Parallax()
{

}

void Game::Parallax::addLayer(sf::Sprite sprite, sf::Texture texture, std::pair<int, int> positions, float speed)
{
    _sprites.push_back(sprite);
    _textures.push_back(texture);
    _positions.push_back(positions);
    _speeds.push_back(speed);
}

void Game::Parallax::update(sf::RenderWindow &window, float deltaTime)
{
    for (std::size_t i = 0; i < _sprites.size(); i++) {
        _positions[i].first -= _speeds[i] * deltaTime;
        if (_positions[i].first < -1920)
            _positions[i].first = 1920;
        _sprites[i].setPosition(_positions[i].first, _positions[i].second);
    }
}