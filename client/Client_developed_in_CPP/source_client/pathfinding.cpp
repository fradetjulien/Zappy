//
// EPITECH PROJECT, 2018
// Zappy
// File description:
// Functions for pathfinding
//

#include <iostream>
#include "../include_client/ia.hpp"

int	Ia::getTravelTime(int x, int y)
{
	int	x_diff = 0;
	int	y_diff = 0;
	int	totalTrvlTime = 0;
	
	if (x > _posPlayer.first) {
		x_diff = x - _posPlayer.first;
	} else if (x < _posPlayer.first) {
		x_diff = _posPlayer.first - x;
	} else
		x_diff = 0;
	if (y > _posPlayer.second) {
		y_diff = y - _posPlayer.second;
	} else if (y < _posPlayer.second) {
		y_diff = _posPlayer.second - y;
	} else
		y_diff = 0;
	totalTrvlTime = x_diff + y_diff;
	if (x_diff != 0 && y_diff != 0)
		totalTrvlTime += 1;
	return totalTrvlTime;
}

void	Ia::pathFinding()
{
    std::cout << _priorityPos.first << " - " << _priorityPos.second << std::endl;
	int x = _priorityPos.first;
	int y = _priorityPos.second;
	int	travelTime = getTravelTime(x, y);

	switch (_playerOrientation) {
	case NORTH:
		getPathNorth(x, y);
		break;
	case EAST:
		getPathEast(x, y);
		break;
	case WEST:
		getPathWest(x, y);
		break;
	case SOUTH:
		getPathSouth(x, y);
		break;
	default:
		break;
	}
	_needFood = travelTime < _lifetime;
}

void	Ia::getPathNorth(int x, int y)
{
	int	tmp_y = 0;
	int	tmp_x = 0;

    std::cout << "non1" << std::endl;
	if (_posPlayer.second > y) {
        std::cout << "non2" << std::endl;
		tmp_y = _posPlayer.second;
		while (tmp_y > y) {
            std::cout << "non" << std::endl;
			_actions.push_back(FORWARD);
			tmp_y--;
		}
	}
	if (x < _posPlayer.first) {
        std::cout << "non2" << std::endl;
		tmp_x = _posPlayer.first;
		_actions.push_back(LEFT);
		while (tmp_x > x) {
            std::cout << "non" << std::endl;
			_actions.push_back(FORWARD);
			tmp_x--;
		}
	}
	else if (x > _posPlayer.first) {
        std::cout << "non2" << std::endl;
		tmp_x = x;
		_actions.push_back(RIGHT);
		while (tmp_x < x) {
            std::cout << "non" << std::endl;
			_actions.push_back(FORWARD);
			tmp_x++;
		}
	}
	_posPlayer.first = tmp_x;
	_posPlayer.second = tmp_y;
    std::cout <<"pos x = " << _posPlayer.first << std::endl;
    std::cout <<"pos y = " << _posPlayer.second << std::endl;
}

void	Ia::getPathEast(int x, int y)
{
	int	tmp_x = 0;
	int	tmp_y = 0;

	if (x > _posPlayer.first) {
		tmp_x = _posPlayer.first;
		while (tmp_x < x) {
			_actions.push_back(FORWARD);
			tmp_x++;
		}
	}
	if (y < _posPlayer.second) {
		tmp_y = _posPlayer.second;
		_actions.push_back(LEFT);
		while (tmp_y > y) {
			_actions.push_back(FORWARD);
			tmp_y--;
		}
	}
	else if (y > _posPlayer.second) {
		tmp_y = y;
		_actions.push_back(RIGHT);
		while (tmp_y < y) {
			_actions.push_back(FORWARD);
			tmp_y++;
		}
	}
	_posPlayer.first = tmp_x;
	_posPlayer.second = tmp_y;
    std::cout <<"pos x = " << _posPlayer.first << std::endl;
    std::cout <<"pos y = " << _posPlayer.second << std::endl;
}

void	Ia::getPathWest(int x, int y)
{
	int	tmp_x = 0;
	int	tmp_y = 0;

	if (x < _posPlayer.first) {
		tmp_x = _posPlayer.first;
		while (tmp_x > x) {
			_actions.push_back(FORWARD);
			tmp_x--;
		}
	}
	if (y < _posPlayer.second) {
		tmp_y = _posPlayer.second;
		_actions.push_back(LEFT);
		while (tmp_y > y) {
			_actions.push_back(FORWARD);
			tmp_y--;
		}
	}
	else if (y > _posPlayer.second) {
		tmp_y = y;
		_actions.push_back(RIGHT);
		while (tmp_y < y) {
			_actions.push_back(FORWARD);
			tmp_y++;
		}
	}
	_posPlayer.first = tmp_x;
	_posPlayer.second = tmp_y;
    std::cout <<"pos x = " << _posPlayer.first << std::endl;
    std::cout <<"pos y = " << _posPlayer.second << std::endl;
}

void	Ia::getPathSouth(int x, int y)
{
	int	tmp_y = 0;
	int	tmp_x = 0;
	
	if (_posPlayer.second < y) {
		tmp_y = _posPlayer.second;
		while (tmp_y < y) {
			_actions.push_back(FORWARD);
			tmp_y++;
		}
	}
	if (x < _posPlayer.first) {
		tmp_x = _posPlayer.first;
		_actions.push_back(LEFT);
		while (tmp_x > x) {
			_actions.push_back(FORWARD);
			tmp_x--;
		}
	}
	else if (x > _posPlayer.first) {
		tmp_x = x;
		_actions.push_back(RIGHT);
		while (tmp_x < x) {
			_actions.push_back(FORWARD);
			tmp_x++;
		}
	}
	_posPlayer.first = tmp_x;
	_posPlayer.second = tmp_y;
    std::cout <<"pos x = " << _posPlayer.first << std::endl;
    std::cout <<"pos y = " << _posPlayer.second << std::endl;
}
