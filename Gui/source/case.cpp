//
// Created by torres_l on 30/06/18.
//

#include "case.hpp"

Case::Case(std::size_t x, std::size_t y)
{
    _posX = x;
    _posY = y;
    _ground.setFillColor(sf::Color::Blue);
    _ground.setSize(sf::Vector2f(BLOCK, BLOCK));
    _ground.setOutlineColor(sf::Color::Black);
    _ground.setOutlineThickness(5);
    _ground.setPosition(_posX * BLOCK, _posY * BLOCK);
    _player = 0;
}

std::pair<std::size_t, std::size_t> Case::generateRandom()
{
    std::pair<std::size_t, std::size_t> tmp;

    if (_posX == 0)
        tmp.first = std::rand() % (_posX * BLOCK + BLOCK);
    else
        tmp.first = std::rand() % (BLOCK) + (_posX * BLOCK);
    if (_posY == 0)
        tmp.second = std::rand() % (_posY * BLOCK + BLOCK);
    else
        tmp.second = std::rand() % (BLOCK) + (_posY * BLOCK);
    return (tmp);
}

void Case::createLinemate(int nb, sf::Color color)
{
    _linemate.setRadius(5);
    _linemate.setPointCount(3);
    if (nb != 0) {
        std::pair<std::size_t, std::size_t> tmp = generateRandom();
        _linemate.setFillColor(color);
        _linemate.setPosition(tmp.first, tmp.second);
    }
    else
        _linemate.setPosition(-10, -10);
}

void Case::createDeraumere(int nb, sf::Color color)
{
    _deraumere.setRadius(5);
    _deraumere.setPointCount(4);
    if (nb != 0) {
        std::pair<std::size_t, std::size_t> tmp = generateRandom();
        _deraumere.setFillColor(color);
        _deraumere.setPosition(tmp.first, tmp.second);
    }
    else
        _deraumere.setPosition(-10, -10);
}

void Case::createSibur(int nb, sf::Color color)
{
    _sibur.setRadius(5);
    _sibur.setPointCount(5);
    if (nb != 0) {
        std::pair<std::size_t, std::size_t> tmp = generateRandom();
        _sibur.setFillColor(color);
        _sibur.setPosition(tmp.first, tmp.second);
    }
    else
        _sibur.setPosition(-10, -10);
}

void Case::createMendiane(int nb, sf::Color color)
{
    _mendiane.setRadius(5);
    _mendiane.setPointCount(6);
    if (nb != 0) {
        std::pair<std::size_t, std::size_t> tmp = generateRandom();
        _mendiane.setFillColor(color);
        _mendiane.setPosition(tmp.first, tmp.second);
    }
    else
        _mendiane.setPosition(-10, -10);
}

void Case::createPhiras(int nb, sf::Color color)
{
    _phiras.setRadius(5);
    _phiras.setPointCount(7);
    if (nb != 0) {
        std::pair<std::size_t, std::size_t> tmp = generateRandom();
        _phiras.setFillColor(color);
        _phiras.setPosition(tmp.first, tmp.second);
    }
    else
        _phiras.setPosition(-10, -10);
}

void Case::createThystame(int nb, sf::Color color)
{
    _thystame.setRadius(5);
    _thystame.setPointCount(8);
    if (nb != 0) {
        std::pair<std::size_t, std::size_t> tmp = generateRandom();
        _thystame.setFillColor(color);
        _thystame.setPosition(tmp.first, tmp.second);
    }
    else
        _thystame.setPosition(-10, -10);
}

void Case::createFood(int nb, sf::Color color)
{
    _food.setRadius(5);
    _food.setPointCount(9);
    if (nb != 0) {
        std::pair<std::size_t, std::size_t> tmp = generateRandom();
        _food.setFillColor(color);
        _food.setPosition(tmp.first, tmp.second);
    }
    else
        _food.setPosition(-10, -10);
}

sf::CircleShape Case::getLinemate()
{
    return (_linemate);
}

sf::CircleShape Case::getDeraumere()
{
    return (_deraumere);
}

sf::CircleShape Case::getSibur() {
    return (_sibur);
}

sf::CircleShape Case::getMendiane() {
    return (_mendiane);
}

sf::CircleShape Case::getPhiras() {
    return (_phiras);
}

sf::CircleShape Case::getThystame() {
    return (_thystame);
}

sf::CircleShape Case::getFood() {
    return (_food);
}

sf::RectangleShape Case::getGround() {
    return (_ground);
}

void Case::createPlayer(sf::Sprite tmp) {
    _playerSprite = tmp;
}

sf::Sprite Case::getPlayer() {
    return (_playerSprite);
}


