/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Player
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

namespace Game {

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

    class Player {
        public:
            Player(const std::string &texture);
            ~Player();
            void move(Direction direction, float dtime);
            void update();
            void draw(sf::RenderWindow &window);
            void setPosition(std::pair<int, int> position);
            void setSize(std::pair<int, int> size);
            void setSpeed(int speed);
            void setDirection(Direction direction);
            std::pair<int, int> getPosition();
            std::pair<int, int> getSize();
            int getSpeed();
            Direction getDirection();
        protected:
        private:
            sf::RenderWindow _window;
            sf::Texture _texture;
            sf::Sprite _sprite;
            std::pair<int, int> _position;
            std::pair<int, int> _size;
            int _speed;
            Direction _direction;
    };
}
