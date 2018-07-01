//
// Created by torres_l on 12/06/18.
//

#ifndef PSU_ZAPPY_2017_IA_HPP
#define PSU_ZAPPY_2017_IA_HPP

#include <unordered_map>
#include <vector>

enum Priority {
    USELESS = 0,
    VERY_LOW = 1,
    LOW = 2,
    MEDIUM = 3,
    HIGH = 4,
    VERY_HIGH = 5,
    RARE = 6
};

enum Move {
    FORWARD,
    LEFT,
    RIGHT
};

enum Fakeorientation {
    FNORTH = -1,
    FSOUTH = 1,
    FEAST = 1,
    FWEST = -1
};

enum Orientation {
    NORTH,
    EAST,
    WEST,
    SOUTH
};

class Ia {
public:
    Ia();
    ~Ia() = default;
    void parseLook(const std::string &);
    void parseInventory(const std::string &);
    void initPlayer();
    void handlePpo(const std::string &);
    void handlePlv(const std::string &);
    void	pathFinding();
    void setSizeMap(int, int);
    std::string doActions(const std::size_t &);
    std::string getPriority() const;
    void checkLevelUp();
    bool needLevelUp() const;
    std::size_t     _level;

private:
    std::vector<std::unordered_map<std::string, Priority >>  _priorityByLevel;
    std::vector<std::unordered_map<std::string, std::size_t>> _needByLevel;
    std::unordered_map<std::string, std::size_t>    _inventory;
    std::pair<int, int> _priorityPos;
    std::pair<int, int> _posPlayer;
    std::pair<int, int> _sizeMap;
    std::string _priority;
    std::size_t _indexLook;
    std::string _ressources;
    std::string _invSlot;
    Fakeorientation _fakeOrientation;
    std::vector<Move>					_actions;
    int							_lifetime;
    Orientation						_playerOrientation;
    bool    _needFood;
    bool    _levelUp;

    void initPriority();
    void initNeed();
    std::vector<std::string> getParsedVector(const std::string &);
    void parseTitle(const std::string &, const std::size_t &);
    void parseInvSlot(const std::string &);
    void checkPriority(const std::size_t &);
    void getPosByIndex();
    void getFrontPos(const std::size_t &);
    void getLeftPos(const std::size_t &);
    void getRightPos(const std::size_t &);
    void handleOutMapX(int toward);
    void handleOutMapY(int toward);
    template <typename T>
    std::unordered_map<std::string, T>    createMap(const std::vector<T> &);

    void	getPathSouth(int x, int y);
    void	getPathWest(int x, int y);
    void	getPathEast(int x, int y);
    void	getPathNorth(int x, int y);
    int getTravelTime(int x, int y);
};

#endif //PSU_ZAPPY_2017_IA_HPP
