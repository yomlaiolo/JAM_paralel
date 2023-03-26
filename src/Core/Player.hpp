/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Player
*/

#pragma once

#include "IBlock.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>

namespace Game {
    class Player {
        public:
            Player(const std::string &texture, sf::Vector2f pos);
            ~Player();
            void move(Direction direction, float dtime);
            void update(const float &dtime, int direction);
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
            void setJumping(bool isJumping);
            bool isJumping();
            bool checkCollision(const std::vector<IBlock *> &blocks, float dtime);
        protected:
        private:
            sf::RenderWindow _window;
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::Vector2f _position;
            sf::Vector2f _size;
            sf::Vector2f _scale;
            int _speed;
            Direction _direction;
            int _anim_x;
            int _anim_y;
            float _time;
            float _timesincelastjump;
            bool _isJumping;
    };
}
