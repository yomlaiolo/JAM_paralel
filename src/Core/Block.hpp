/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** ABlock
*/

#pragma once

#include "Enum.hpp"
#include "IBlock.hpp"
#include "Player.hpp"

namespace Game {
    class Block : public Game::IBlock {
        public:
            Block(const std::string &texture, const sf::Vector2f &coords, const sf::Vector2f &size);
            ~Block();
            void setTexture(const std::string &texture);
            void setCoords(const sf::Vector2f &coords);
            void setSize(const sf::Vector2f &size);
            void setSolid(bool isSolid);
            void setEvent(const Game::Event &event);
            void setSprite();
            sf::Vector2f getCoords() const;
            sf::Vector2f getSize() const;
            sf::Sprite getSprite() const;
            sf::Texture getTexture() const;
            bool isSolid() const;
            bool isEvent() const;
            Game::Event getEvent() const;
            void update(float deltaTime, Game::Direction direction);
            void draw(sf::RenderWindow &window);
        protected:
        private:
            sf::Vector2f _coords;
            sf::Vector2f _size;
            sf::Sprite _sprite;
            sf::Texture _texture;
            bool _isSolid;
            bool _isEvent;
            Game::Event _event;
    };
}
