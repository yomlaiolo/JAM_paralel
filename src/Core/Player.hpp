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
            Player(const std::string &texture, sf::Vector2f pos);
            ~Player();
            void move(Direction direction, float dtime);
            void update(const float &dtime);
            void draw(sf::RenderWindow &window);
            void setPosition(sf::Vector2f position);
            void setSize(sf::Vector2f size);
            void setSpeed(int speed);
            void setDirection(Direction direction);
            void setScale(sf::Vector2f scale);
            sf::Vector2f getPosition();
            sf::Vector2f getSize();
            int getSpeed();
            Direction getDirection();
        protected:
        private:
            sf::RenderWindow _window;
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::Vector2f _position;
            sf::Vector2f _size;
            int _speed;
            Direction _direction;
            int _anim_x;
            int _anim_y;
            float _time;
    };
}
