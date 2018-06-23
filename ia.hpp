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

class Ia {
public:
    Ia();
    ~Ia() = default;
    void parseLook(const std::string &);
    void initPriority();
    std::unordered_map<std::string, Priority>   createPriority(const std::vector<Priority> &);

private:
    std::vector<std::unordered_map<std::string, Priority >>  _priorityByLevel;
};

#endif //PSU_ZAPPY_2017_IA_HPP
