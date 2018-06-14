//
// Created by torres_l on 12/06/18.
//

#include <iostream>
#include "ia.hpp"

void Ia::parseLook(const std::string &look)
{
    std::size_t firstPos = look.find(',');
    std::size_t secondPos;


}

Ia::Ia() {
    _level = 0;
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

    return tmp;
}
