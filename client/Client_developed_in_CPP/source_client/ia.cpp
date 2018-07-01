//
// Created by torres_l on 12/06/18.
//

#include <iostream>
#include <sstream>
#include "../include_client/ia.hpp"

void Ia::parseLook(const std::string &look)
{
    std::size_t i = 1;
    std::size_t firstComma = look.find(',');
    std::size_t lastComma = look.find_last_of(',');
    std::size_t secondComma;

    _priority.clear();
    _ressources = look.substr(look.find('[') + 1, firstComma - 1);
    parseTitle(_ressources, 0);
    while (firstComma != lastComma) {
        secondComma = look.find(',', firstComma + 1);
        _ressources = look.substr(firstComma + 1, secondComma - firstComma - 1);
        parseTitle(_ressources, i);
        firstComma = secondComma;
        i++;
    }
    lastComma = look.find(']');
    _ressources = look.substr(firstComma + 1, lastComma - firstComma - 1);
    parseTitle(_ressources, i);
    getPosByIndex();
}

void Ia::parseTitle(const std::string &look, const std::size_t &i)
{
    std::istringstream iss(look);
    while (std::getline(iss, _ressources, ' ')) {
        checkPriority(i);
    }
}

Ia::Ia() {
}

void Ia::initPriority()
{
    std::vector<Priority>   tmp{VERY_HIGH, USELESS, USELESS, USELESS, USELESS, USELESS, VERY_LOW};
    _priorityByLevel.push_back(createMap(tmp));
    tmp = {MEDIUM, HIGH, VERY_HIGH, USELESS, USELESS, RARE, USELESS};
    _priorityByLevel.push_back(createMap(tmp));
    tmp = {MEDIUM, USELESS, HIGH, USELESS, VERY_HIGH, RARE, USELESS};
    _priorityByLevel.push_back(createMap(tmp));
    tmp = {LOW, MEDIUM, HIGH, USELESS, VERY_HIGH, RARE, USELESS};
    _priorityByLevel.push_back(createMap(tmp));
    tmp = {LOW, MEDIUM, HIGH, VERY_HIGH, USELESS, RARE, USELESS};
    _priorityByLevel.push_back(createMap(tmp));
    tmp = {LOW, MEDIUM, HIGH, USELESS, VERY_HIGH, RARE, USELESS};
    _priorityByLevel.push_back(createMap(tmp));
    tmp = {VERY_LOW, LOW, MEDIUM, HIGH, VERY_HIGH, RARE, USELESS};
    _priorityByLevel.push_back(createMap(tmp));
}

void Ia::checkPriority(const std::size_t &i)
{
    if (_inventory[_ressources] <_needByLevel[_level - 1][_ressources]) {
        if (_priorityByLevel[_level - 1][_ressources] > _priorityByLevel[_level - 1][_priority]) {
            _priority = _ressources;
            _indexLook = i;
        }
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
        if (_fakeOrientation == FNORTH || _fakeOrientation == FSOUTH) {
            _priorityPos.first = _posPlayer.first;
            handleOutMapY(_fakeOrientation);
        }
        else if (_fakeOrientation == FWEST || _fakeOrientation == FEAST) {
            _priorityPos.second = _posPlayer.second;
            handleOutMapX(_fakeOrientation);
        }
    }
}

void Ia::getLeftPos(const std::size_t &tmp)
{
    for (std::size_t i = tmp; i != _indexLook; i--) {
        if (_fakeOrientation == FNORTH)
            handleOutMapX(-1);
        else if (_fakeOrientation == FSOUTH)
            handleOutMapX(1);
        else if (_fakeOrientation == FEAST)
            handleOutMapY(-1);
        else if (_fakeOrientation == FWEST)
            handleOutMapY(1);
    }
}

void Ia::getRightPos(const std::size_t &tmp)
{
    for (std::size_t i = tmp; i != _indexLook; i++) {
        if (_fakeOrientation == FNORTH)
            handleOutMapX(1);
        else if (_fakeOrientation == FSOUTH)
            handleOutMapX(-1);
        else if (_fakeOrientation == FEAST)
            handleOutMapY(1);
        else if (_fakeOrientation == FWEST)
            handleOutMapY(-1);
    }
}

void Ia::handleOutMapX(int toward)
{
    if (_priorityPos.first + toward > _sizeMap.first - 1)
        _priorityPos.first = 0;
    else if (_priorityPos.first + toward < 0)
        _priorityPos.first = _sizeMap.first;
    else
        _priorityPos.first += toward;
}

void Ia::handleOutMapY(int toward)
{
    if (_priorityPos.second + toward > _sizeMap.second - 1)
        _priorityPos.second = 0;
    else if (_priorityPos.second + toward < 0)
        _priorityPos.second = _sizeMap.second;
    else
        _priorityPos.second += toward;
}

void Ia::handlePpo(const std::string &answer)
{
    std::vector<std::string> parse = getParsedVector(answer);
    _posPlayer.first = std::atoi(parse[2].c_str());
    _posPlayer.second = std::atoi(parse[3].c_str());
    _priorityPos.first = _posPlayer.first;
    _priorityPos.second = _posPlayer.second;
    int i = std::atoi(parse[4].c_str());
    if (i == 1) {
        _fakeOrientation = FNORTH;
        _playerOrientation = NORTH;
        }
    else if (i == 2) {
        _fakeOrientation = FEAST;
        _playerOrientation = EAST;
    }
    else if (i == 3) {
        _fakeOrientation = FSOUTH;
        _playerOrientation = SOUTH;
    }
    else {
        _fakeOrientation = FWEST;
        _playerOrientation = WEST;
    }
}

void Ia::handlePlv(const std::string &answer)
{
    std::vector<std::string> parse = getParsedVector(answer);
    _level = static_cast<size_t>(std::atoi(parse[1].c_str()));
}

std::vector<std::string> Ia::getParsedVector(const std::string &answer)
{
    std::istringstream  iss(answer);
    std::string tmp;
    std::vector<std::string>    parse;

    while (std::getline(iss, tmp, ' ')) {
        parse.push_back(tmp);
    }
    return parse;
}

void Ia::initPlayer()
{
    initPriority();
    initNeed();
}

void Ia::initNeed()
{
    std::vector<std::size_t>   tmp{1, 0, 0, 0, 0, 0, 999};
    _needByLevel.push_back(createMap(tmp));
    tmp = {1, 1, 1, 0, 0, 0, 999};
    _needByLevel.push_back(createMap(tmp));
    tmp = {2, 0, 1, 0, 2, 0, 999};
    _needByLevel.push_back(createMap(tmp));
    tmp = {1, 1, 2, 0, 1, 0, 999};
    _needByLevel.push_back(createMap(tmp));
    tmp = {1, 2, 1, 3, 0, 0, 999};
    _needByLevel.push_back(createMap(tmp));
    tmp = {1, 2, 3, 0, 1, 0, 999};
    _needByLevel.push_back(createMap(tmp));
    tmp = {2, 2, 2, 2, 2, 1, 999};
    _needByLevel.push_back(createMap(tmp));
}

template<typename T>
std::unordered_map<std::string, T> Ia::createMap(const std::vector<T> &prio)
{
    std::unordered_map<std::string, T>  tmp;

    tmp["linemate"] = prio[0];
    tmp["deraumere"] = prio[1];
    tmp["sibur"] = prio[2];
    tmp["mendiane"] = prio[3];
    tmp["phiras"] = prio[4];
    tmp["thystame"] = prio[5];
    tmp["food"] = prio[6];

    return tmp;
}

void Ia::parseInventory(const std::string &inventory)
{
    std::size_t i = 1;
    std::size_t firstComma = inventory.find(',');
    std::size_t lastComma = inventory.find_last_of(',');
    std::size_t secondComma;

    _invSlot = inventory.substr(inventory.find('['), firstComma - 1);
    parseInvSlot(_invSlot);
    while (firstComma != lastComma) {
        secondComma = inventory.find(',', firstComma + 1);
        _invSlot = inventory.substr(firstComma + 1, secondComma - firstComma - 1);
        parseInvSlot(_invSlot);
        firstComma = secondComma;
        i++;
    }
    lastComma = inventory.find(']');
    _invSlot = inventory.substr(firstComma + 1, lastComma - firstComma - 1);
    parseInvSlot(_invSlot);
}

void Ia::parseInvSlot(const std::string &slot)
{
    std::istringstream iss(slot);
    std::size_t nb = 0;
    std::string tmp;

    while (std::getline(iss, _invSlot, ' ')) {
        if (nb == 0)
            tmp = _invSlot;
        else
            _inventory[tmp] = static_cast<std::size_t>(std::atoi(_invSlot.c_str()));
        nb++;
    }

}

void Ia::setSizeMap(int x, int y)
{
    _sizeMap.first = x;
    _sizeMap.second = y;
}

std::string Ia::doActions(const std::size_t &i)
{
    if (i >= _actions.size())
        return ("stop");
    if (_actions[i] == FORWARD)
        return ("Forward");
    else if (_actions[i] == LEFT)
        return ("Left");
    else if (_actions[i] == RIGHT)
        return ("Right");
    return ("stop");
}

std::string Ia::getPriority() const {
    return (_priority);
}

void Ia::checkLevelUp()
{
    if (_inventory["linemate"] >= _needByLevel[_level]["linemate"])
        _levelUp = true;
    else
        _levelUp = false;

}

bool Ia::needLevelUp() const
{
    return (_levelUp);
}
