/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** ABlock
*/

#pragma once

#include "IBlock.hpp"

namespace Game {
    class Block : public Game::IBlock {
        public:
            Block(const std::string &texture, const std::pair<int, int> &coords, const std::pair <int, int> &size);
            ~Block();
            void setTexture(const std::string &texture);
            void setCoords(const std::pair<int, int> &coords);
            void setSize(const std::pair <int, int> &size);
            void setSolid(bool isSolid);
            void setEvent(const Game::Event &event);
            void setSprite();
            std::pair<int, int> getCoords() const;
            std::pair<int, int> getSize() const;
            sf::Sprite getSprite() const;
            sf::Texture getTexture() const;
            bool isSolid() const;
            bool isEvent() const;
            Game::Event getEvent() const;
        protected:
        private:
            std::pair<int, int> _coords;
            std::pair<int, int> _size;
            sf::Sprite _sprite;
            sf::Texture _texture;
            bool _isSolid;
            bool _isEvent;
            Game::Event _event;
    };
}
