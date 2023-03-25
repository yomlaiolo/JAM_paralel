/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** IBlock
*/

#pragma once

#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <string>

namespace Game {
    enum Event {
        NO,
        DOOR,
        KEY,
        TP,
        CHEST,
        ENEMY,
        BOSS,
        PLAYER,
        EXIT
    };
    
    class IBlock {
        public:
            virtual ~IBlock() = default;
            virtual void setTexture(const std::string &texture) = 0;
            virtual void setCoords(const sf::Vector2f &coords) = 0;
            virtual void setSize(const sf::Vector2f &size) = 0;
            virtual void setSolid(bool isSolid) = 0;
            virtual void setEvent(const Game::Event &event) = 0;
            virtual void setSprite() = 0;
            virtual sf::Vector2f getCoords() const = 0;
            virtual sf::Vector2f getSize() const = 0;
            virtual sf::Sprite getSprite() const = 0;
            virtual sf::Texture getTexture() const = 0;
            virtual bool isSolid() const = 0;
            virtual bool isEvent() const = 0;
            virtual Game::Event getEvent() const = 0;
            virtual void draw(sf::RenderWindow &window) = 0;
        protected:
        private:
    };
}
