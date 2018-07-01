//
// Created by torres_l on 27/06/18.
//

#include "gui.hpp"
#include "exception.hpp"

Gui::Gui(int maxX, int maxY)
{
    _win.create(sf::VideoMode(1200, 1200), "Zappy");
    if (!_texturePlayer.loadFromFile("Gui/assets/player.png", sf::IntRect(6, 1146, 44, 44)))
        throw MyError("texture error");
    _maxX = maxX;
    _maxY = maxY;
}

Gui::~Gui() {
    _win.close();
}

void Gui::parseTitle(const std::string &title, bool newCase)
{
    std::istringstream  iss(title);
    std::string str;
    std::vector<std::string> tmp;

    while (std::getline(iss, str, ' ')) {
        tmp.push_back(str);
    }
    drawRessources(tmp, newCase);
}

void Gui::drawRessources(const std::vector<std::string> &rsrc, bool newCase)
{
    std::size_t x = static_cast<size_t>(std::atoi(rsrc[1].c_str()));
    std::size_t y = static_cast<size_t>(std::atoi(rsrc[2].c_str()));

    if (newCase) {
        std::unique_ptr<Case> tmp(new Case(x, y));
        _map.push_back(std::move(tmp));
    }

    _map[x + (y * _maxY)]->createLinemate(std::atoi(rsrc[3].c_str()), sf::Color::Green);
    _map[x + (y * _maxY)]->createDeraumere(std::atoi(rsrc[4].c_str()), sf::Color::Magenta);
    _map[x + (y * _maxY)]->createSibur(std::atoi(rsrc[5].c_str()), sf::Color::Yellow);
    _map[x + (y * _maxY)]->createMendiane(std::atoi(rsrc[6].c_str()), sf::Color::White);
    _map[x + (y * _maxY)]->createPhiras(std::atoi(rsrc[7].c_str()), sf::Color::Cyan);
    _map[x + (y * _maxY)]->createThystame(std::atoi(rsrc[8].c_str()), sf::Color(32, 32, 32));
    _map[x + (y * _maxY)]->createFood(std::atoi(rsrc[9].c_str()), sf::Color(132, 132, 132));
}

void Gui::parsePlayer(const std::string &player)
{
    std::istringstream iss(player);
    std::string str;
    std::vector<std::string> tmp;

    while (std::getline(iss, str, ' ')) {
        tmp.push_back(str);
    }
    if (tmp[2] == "-1")
        return ;
    sf::Sprite  tmpSprite;
    std::size_t x = static_cast<size_t>(std::atoi(tmp[2].c_str()));
    std::size_t y = static_cast<size_t>(std::atoi(tmp[3].c_str()));
    _actualPosPlayer.emplace_back(std::make_pair(x, y));
    tmpSprite.setTexture(_texturePlayer);
    tmpSprite.setPosition(x * BLOCK, y * BLOCK);
    _map[x + (y * _maxY)]->_player = 1;
    _map[x + (y * _maxY)]->createPlayer(tmpSprite);
}

void Gui::handleEvent()
{
    if (_win.isOpen()) {
        while (_win.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _win.close();
        }
    }
}

void Gui::clearWin()
{
    for (auto &i : _map) {
        if (i->_player == 1)
            i->_player = 0;
    }
    _win.clear();
}

void Gui::displayWin()
{
    _win.display();
}

void Gui::drawMap()
{
    for (auto &i : _map) {
        _win.draw(i->getGround());
        _win.draw(i->getLinemate());
        _win.draw(i->getDeraumere());
        _win.draw(i->getSibur());
        _win.draw(i->getMendiane());
        _win.draw(i->getPhiras());
        _win.draw(i->getThystame());
        _win.draw(i->getFood());
        if (i->_player == 1) {
            _win.draw(i->getPlayer());
        }
    }
}

void Gui::savePos()
{
    _savePosPlayer = _actualPosPlayer;
}

bool Gui::checkPos() const
{
    for (std::size_t i = 0; i < _savePosPlayer.size(); i++) {
        if (_actualPosPlayer[i].first != _savePosPlayer[i].first ||
            _actualPosPlayer[i].second != _savePosPlayer[i].second) {
            return (true);
        }
    }
    return (false);
}

bool Gui::saveEmpty() const
{
    return (_savePosPlayer.empty());
}

std::vector<std::pair<size_t, size_t>> Gui::getActualPos() const
{
    return (_actualPosPlayer);
}

void Gui::resetActualPos()
{
    _actualPosPlayer.clear();
}
