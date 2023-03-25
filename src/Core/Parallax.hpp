/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Parallax
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

namespace Game {
    class Parallax {
        public:
            Parallax();
            ~Parallax();
            void addLayer(sf::Sprite sprite, sf::Texture texture, std::pair<int, int> positions, float speed);
            void update(sf::RenderWindow &window, float deltaTime);
            void draw(sf::RenderWindow &window);
        protected:
        private:
            sf::RenderWindow _window;
            std::vector<sf::Sprite> _sprites;
            std::vector<sf::Texture> _textures;
            std::vector<std::pair<int, int>> _positions;
            std::vector<float> _speeds;
    };
}

