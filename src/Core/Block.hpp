/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** ABlock
*/

#pragma once

#include "IBlock.hpp"

namespace Game {
    class ABlock;
}

class ABlock : public IBlock {
    public:
        ABlock(std::string texture, std::pair <int, int> coords, std::pair <int, int> size);
        ~ABlock();
        void setTexture(std::string texture);
        void setCoords(std::pair <int, int> coords);
        void setSize(std::pair <int, int> size);
        void setSolid(bool isSolid);
        void setEvent(Game::Event event);
        void setSprite();
        std::pair <int, int> getCoords() const;
        std::pair <int, int> getSize() const;
        sf::Sprite getSprite() const;
        sf::Texture getTexture() const;
        bool isSolid() const;
        bool isEvent() const;
        Game::Event getEvent() const;
    protected:
    private:
        std::pair <int, int> _coords;
        std::pair <int, int> _size;
        sf::Sprite _sprite;
        sf::Texture _texture;
        bool _isSolid;
        bool _isEvent;
        Game::Event _event;
};
