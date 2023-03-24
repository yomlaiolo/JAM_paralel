/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Block
*/

#include "Block.hpp"

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