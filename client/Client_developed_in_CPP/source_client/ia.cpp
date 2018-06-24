//
// Created by torres_l on 12/06/18.
//

#include <iostream>
#include <sstream>
#include "../include_client/ia.hpp"

void Ia::parseLook(const std::string &look)
{
    std::size_t i = 1;
    _firstComma = look.find(',');
    _lastComma = look.find_last_of(',');

    while (_firstComma != _lastComma) {
        _secondComma = look.find(',', _firstComma + 1);
        _ressources = look.substr(_firstComma + 1, _secondComma - _firstComma - 1);
        parseTitle(_ressources, i);
        _firstComma = _secondComma;
        i++;
    }
    _lastComma = look.find(']');
    _ressources = look.substr(_firstComma + 1, _lastComma - _firstComma - 1);
    std::cout << _ressources << " at index : " << i << std::endl;
    checkPriority(i);
    getPosByIndex();
    std::cout << "x = " <<_priorityPos.first << " y = " << _priorityPos.second << std::endl;
}

void Ia::parseTitle(const std::string &look, const std::size_t &i)
{
    std::istringstream iss(look);
    while (std::getline( iss, _ressources, ' ' )) {
        std::cout << _ressources << " at index : " << i << std::endl;
        checkPriority(i);
    }
}

Ia::Ia() {
    _level = 3;
    _posPlayer.first = 10;
    _posPlayer.second = 10;
    _priorityPos.first = 10;
    _priorityPos.second = 10;
    _playerOrientation = NORTH;
}

void Ia::initPriority()
{
    std::vector<Priority>   tmp{VERY_HIGH, USELESS, USELESS, USELESS, USELESS, RARE};
    _priorityByLevel.push_back(createPriority(tmp));
    tmp = {MEDIUM, HIGH, VERY_HIGH, USELESS, USELESS, RARE};
    _priorityByLevel.push_back(createPriority(tmp));
    tmp = {MEDIUM, USELESS, HIGH, USELESS, VERY_HIGH, RARE};
    _priorityByLevel.push_back(createPriority(tmp));
    tmp = {LOW, MEDIUM, HIGH, USELESS, VERY_HIGH, RARE};
    _priorityByLevel.push_back(createPriority(tmp));
    tmp = {LOW, MEDIUM, HIGH, VERY_HIGH, USELESS, RARE};
    _priorityByLevel.push_back(createPriority(tmp));
    tmp = {LOW, MEDIUM, HIGH, USELESS, VERY_HIGH, RARE};
    _priorityByLevel.push_back(createPriority(tmp));
    tmp = {VERY_LOW, LOW, MEDIUM, HIGH, VERY_HIGH, RARE};
    _priorityByLevel.push_back(createPriority(tmp));
}

std::unordered_map<std::string, Priority> Ia::createPriority(const std::vector<Priority> &prio)
{
    std::unordered_map<std::string, Priority>  tmp;

    tmp["linemate"] = prio[0];
    tmp["deraumere"] = prio[1];
    tmp["sibur"] = prio[2];
    tmp["mendiane"] = prio[3];
    tmp["phiras"] = prio[4];
    tmp["thystane"] = prio[5];
    tmp["player"] = USELESS;
    tmp["food"] = USELESS;

    return tmp;
}

void Ia::checkPriority(const std::size_t &i)
{
    if (_priority.empty() ||
        _priorityByLevel[_level][_ressources] > _priorityByLevel[_level][_priority]) {
        _priority = _ressources;
        _indexLook = i;
    }
}

void Ia::getPosByIndex()
{
    std::size_t i = 0;
    std::size_t tmp = 0;

    while (i <= _level) {
        tmp = 2 * (i + 1) + tmp;
        if (_indexLook == tmp)
            getFrontPos(i);
        else if (_indexLook < tmp && _indexLook >= tmp - _level) {
            getFrontPos(i);
            getLeftPos(tmp);
        }
        else if (_indexLook > tmp && _indexLook <= tmp + _level) {
            getFrontPos(i);
            getRightPos(tmp);
        }
        i++;
    }
}

void Ia::getFrontPos(const std::size_t &i)
{
    for (std::size_t j = 0; j <= i; j++) {
        if (_playerOrientation == NORTH || _playerOrientation == SOUTH) {
            _priorityPos.first = _posPlayer.first;
            _priorityPos.second += _playerOrientation;
        }
        else if (_playerOrientation == WEST || _playerOrientation == EST) {
            _priorityPos.second = _posPlayer.second;
            _priorityPos.first += _playerOrientation;
        }
    }
}

void Ia::getLeftPos(const std::size_t &tmp)
{
    for (std::size_t i = tmp; i != _indexLook; i--) {
        if (_playerOrientation == NORTH)
            _priorityPos.first -= 1;
        else if (_playerOrientation == SOUTH)
            _priorityPos.first += 1;
        else if (_playerOrientation == EST)
            _priorityPos.second -= 1;
        else if (_playerOrientation == WEST)
            _priorityPos.second += 1;
    }
}

void Ia::getRightPos(const std::size_t &tmp)
{
    for (std::size_t i = tmp; i != _indexLook; i++) {
        if (_playerOrientation == NORTH)
            _priorityPos.first += 1;
        else if (_playerOrientation == SOUTH)
            _priorityPos.first -= 1;
        else if (_playerOrientation == EST)
            _priorityPos.second += 1;
        else if (_playerOrientation == WEST)
            _priorityPos.second -= 1;
    }
}

void Ia::setPosPlayer(const std::string &set)
{

}
