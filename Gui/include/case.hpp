//
// Created by torres_l on 30/06/18.
//

#ifndef PSU_ZAPPY_2017_CASE_HPP
#define PSU_ZAPPY_2017_CASE_HPP

#include <iostream>
#include "SFML/Graphics.hpp"

#define BLOCK (50)

class Case {
public:
    Case(std::size_t, std::size_t);
    ~Case() = default;
    void createLinemate(int, sf::Color);
    void createDeraumere(int, sf::Color);
    void createSibur(int, sf::Color);
    void createMendiane(int, sf::Color);
    void createPhiras(int, sf::Color);
    void createThystame(int, sf::Color);
    void createFood(int, sf::Color);
    void createPlayer(sf::Sprite);
    sf::CircleShape getLinemate();
    sf::CircleShape getDeraumere();
    sf::CircleShape getSibur();
    sf::CircleShape getMendiane();
    sf::CircleShape getPhiras();
    sf::CircleShape getThystame();
    sf::CircleShape getFood();
    sf::RectangleShape getGround();
    sf::Sprite  getPlayer();
    int _player;
    std::size_t _posX;
    std::size_t _posY;

private:
    sf::Sprite  _playerSprite;
    sf::RectangleShape _ground;
    sf::CircleShape _linemate;
    sf::CircleShape _deraumere;
    sf::CircleShape _sibur;
    sf::CircleShape _mendiane;
    sf::CircleShape _phiras;
    sf::CircleShape _thystame;
    sf::CircleShape _food;

    std::pair<std::size_t, std::size_t> generateRandom();
};
#endif //PSU_ZAPPY_2017_CASE_HPP
