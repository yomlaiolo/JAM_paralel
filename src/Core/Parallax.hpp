/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Parallax
*/

#pragma once

#include "Player.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

namespace Game {
    class Parallax {
        public:
            Parallax();
            ~Parallax();
            void addLayer(sf::Sprite sprite, float speed);
            void update(float deltaTime, Game::Direction direction);
            void draw(sf::RenderWindow &window);
        protected:
        private:
            std::vector<sf::Sprite> _sprites;
            std::vector<float> _speeds;
    };
}

