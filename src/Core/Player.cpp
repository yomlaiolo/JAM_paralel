/*
** EPITECH PROJECT, 2023
** JAM_paralel
** File description:
** Player
*/

#include "Player.hpp"

Game::Player::Player(const std::string &texture, sf::Vector2f pos)
{
    _texture.loadFromFile(texture);
    _sprite.setTexture(_texture);
    _position = pos;
    _size = {52, 98};
    _speed = 180;
    _direction = Direction::NONE;
    this->setPosition(pos);
    _anim_x = 0;
    _anim_y = 0;
    _time = 0;
    _timesincelastjump = 0;
    _isJumping = false;
    _scale = {1, 1};
}

Game::Player::~Player()
{

}

void Game::Player::setJumping(bool isJumping)
{
    _isJumping = isJumping;
}

bool Game::Player::isJumping()
{
    return _isJumping;
}

void Game::Player::move(Direction direction, float dtime)
{
    if (direction == Direction::UP)
        _position.y -= _speed * dtime;
    if (direction == Direction::DOWN)
        _position.y += _speed * dtime;
    if (direction == Direction::LEFT)
        _position.x -= _speed * dtime;
    if (direction == Direction::RIGHT)
        _position.x += _speed * dtime;
}

void Game::Player::update(const float &dtime, int direction)
{
    float jumpHeight;

    _time += dtime;
    if (_isJumping) {
        _timesincelastjump += dtime;
        jumpHeight = pow(_timesincelastjump - 0.5, 2) * 75 * direction;
        jumpHeight *= _timesincelastjump > 0.5 ? -1 : 1;
        _position.y -= jumpHeight;

        if (_timesincelastjump >= 0.97) {
            _isJumping = false;
            _timesincelastjump = 0;
            if (_position.y < 500)
                _position.y = 414;
            else
                _position.y = 674;
            _sprite.setPosition(_position.x, _position.y);
        }
    }
    if (_time > 0.2) {
        _time = 0;
        _sprite.setTextureRect(sf::IntRect(52 * _anim_x, 98 * _anim_y, 52, 98));
        _anim_x++;
        if (_anim_x > 5) {
            _anim_x = 0;
            if (_anim_y == 0)
                _anim_y = 1;
            else
                _anim_y = 0;
        }
    }
}

bool Game::Player::checkCollision(const std::vector<IBlock *> &blocks, float dtime)
{
    sf::Vector2f pos = this->getPosition();
    sf::Rect <float> rect(pos.x, pos.y, _size.x, _size.y);
    if (_direction == Direction::UP)
        pos.y -= _speed * dtime;
    if (_direction == Direction::DOWN)
        pos.y += _speed * dtime;
    if (_direction == Direction::LEFT)
        pos.x -= _speed * dtime;
    if (_direction == Direction::RIGHT)
        pos.x += _speed * dtime;
    if (_scale.y == -1)
        rect.top -= _size.y;
    if (_scale.x == -1)
        rect.left -= _size.x;
    for (auto block : blocks) {
        sf::Rect <float> rect2(block->getCoords().x - 8, block->getCoords().y - 8, block->getSize().x + 8, block->getSize().y + 8);
        if (rect.intersects(rect2)) {
            if (block->getType() == '#') {
                return true;
            } else if (block->getType() == 'E') {
                _end = true;
                return false;
            }
        }
    }
    _end = false;
    return false;
}

void Game::Player::draw(sf::RenderWindow &window)
{
    _sprite.setPosition(_position.x, _position.y);
    window.draw(_sprite);
}

void Game::Player::setPosition(sf::Vector2f position)
{
    _position = position;
}

void Game::Player::setSize(sf::Vector2f size)
{
    _size = size;
}

void Game::Player::setSpeed(int speed)
{
    _speed = speed;
}

void Game::Player::setDirection(Direction direction)
{
    _direction = direction;
}

void Game::Player::setScale(sf::Vector2f scale)
{
    _scale = scale;
    _sprite.setScale(scale);
}

sf::Vector2f Game::Player::getPosition()
{
    return _position;
}

sf::Vector2f Game::Player::getSize()
{
    return _size;
}

int Game::Player::getSpeed()
{
    return _speed;
}

Game::Direction Game::Player::getDirection()
{
    return _direction;
}

bool Game::Player::isEnd()
{
    return _end;
}
