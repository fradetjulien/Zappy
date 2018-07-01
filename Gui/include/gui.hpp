//
// Created by torres_l on 27/06/18.
//

#ifndef PSU_ZAPPY_2017_GUI_HPP
#define PSU_ZAPPY_2017_GUI_HPP

#include <sstream>
#include <iostream>
#include <memory>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "case.hpp"

#define BLOCK (50)

class Gui {
public:
    Gui(int , int);
    ~Gui();
    void parseTitle(const std::string &, bool);
    void    parsePlayer(const std::string &);
    void handleEvent();
    void clearWin();
    void    displayWin();
    void drawMap();
    void savePos();
    bool checkPos() const;
    bool    saveEmpty() const;
    std::vector<std::pair<size_t, size_t>> getActualPos() const;
    void resetActualPos();

private:
    std::size_t _maxX;
    std::size_t _maxY;
    sf::Event   _event;
    sf::RenderWindow  _win;
    sf::Texture _texturePlayer;
    std::vector<std::unique_ptr<Case>>  _map;
    std::vector<std::pair<size_t, size_t>>  _savePosPlayer;
    std::vector<std::pair<size_t, size_t>>  _actualPosPlayer;

    void drawRessources(const std::vector<std::string> &, bool);
};

#endif //PSU_ZAPPY_2017_GUI_HPP
