//
// Created by torres_l on 12/06/18.
//

#ifndef PSU_ZAPPY_2017_IA_HPP
#define PSU_ZAPPY_2017_IA_HPP

#include <unordered_map>
#include <vector>

enum Priority {
    USELESS,
    VERY_LOW,
    LOW,
    MEDIUM,
    HIGH,
    VERY_HIGH,
    RARE
};

enum Orientation {
    NORTH = -1,
    SOUTH = 1,
    EST = 1,
    WEST = -1
};

class Ia {
public:
    Ia();
    ~Ia() = default;
    void parseLook(const std::string &);
    void initPriority();

private:
    std::vector<std::unordered_map<std::string, Priority >>  _priorityByLevel;
    std::size_t     _level;
    std::pair<std::size_t, std::size_t> _priorityPos;
    std::pair<std::size_t, std::size_t> _posPlayer;
    std::string _priority;
    std::size_t _indexLook;
    std::size_t _firstComma;
    std::size_t _lastComma;
    std::size_t _secondComma;
    std::string _ressources;
    Orientation _playerOrientation;

    void parseTitle(const std::string &, const std::size_t &);
    void checkPriority(const std::size_t &);
    void getPosByIndex();
    void getFrontPos(const std::size_t &);
    void getLeftPos(const std::size_t &);
    void getRightPos(const std::size_t &);
    std::unordered_map<std::string, Priority>   createPriority(const std::vector<Priority> &);
};

#endif //PSU_ZAPPY_2017_IA_HPP
