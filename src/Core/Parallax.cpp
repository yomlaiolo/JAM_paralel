/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Parallax
*/

#include "Parallax.hpp"

Game::Parallax::Parallax()
{
    _window = window;
    _sprites = std::vector<sf::Sprite>();
    _textures = std::vector<sf::Texture>();
    _positions = std::vector<std::pair<int, int>>();
    _speeds = std::vector<float>();
}

Game::Parallax::~Parallax()
{

}

void Game::Parallax::addLayer(sf::Sprite sprite, sf::Texture texture, std::vector<std::pair<int, int>> _positions, float speed)
{
    _sprites.push_back(sprite);
    _textures.push_back(texture);
    _positions.push_back(_positions);
    _speeds.push_back(speed);
}

void Game::Parallax::update(sf::RenderWindow &window, float deltaTime)
{
    for (int i = 0; i < _sprites.size(); i++) {
        for (int j = 0; j < _positions[i].size(); j++) {
            _sprites[i].setPosition(_positions[i][j].first, _positions[i][j].second);
            _positions[i][j].first -= _speeds[i] * deltaTime;
            if (_positions[i][j].first < -1920)
                _positions[i][j].first = 1920;
            window.draw(_sprites[i]);
        }
    }
}