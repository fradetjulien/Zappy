//
// EPITECH PROJECT, 2018
// Zappy
// File description:
// Functions for pathfinding
//

int	Ia::getTravelTime(int x, int y)
{
	int	x_diff = 0;
	int	y_diff = 0;
	int	totalTrvlTime = 0;
	
	if (x > _x) {
		x_diff = x - _x;
	} else if (x < _x) {
		x_diff = _x - x;
	} else
		x_diff = 0;
	if (y > _y) {
		y_diff = y - _y;
	} else if (y < _y) {
		y_diff = _y - y;
	} else
		y_diff = 0;
	totalTrvlTime = x_diff + y_diff;
	if (x_diff != 0 && y_diff != 0)
		totalTrvlTime += 1;
	return totalTrvlTime;
}

void	Ia::pathFinding(int x, int y)
{
	int	travelTime = getTravelTime(x, y);
	
	switch (_orientation) {
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
	if (travelTime >= _lifetime)
		eat();
	else
		goToPos();
}

void	Ia::getPathNorth(int x, int y)
{
	int	tmp_y = 0;
	int	tmp_x = 0;
	
	if (_y > y) {
		tmp_y = _y;
		while (tmp_y > y) {
			_actions.push_back(FORWARD);
			tmp_y--;
		}
	}
	if (x < _x) {
		tmp_x = _x;
		_actions.push_back(LEFT);
		while (tmp_x > x) {
			_actions.push_back(FORWARD);
			tmp_x--;
		}
	}
	else if (x > _x) {
		tmp_x = x;
		_actions.push_back(RIGHT);
		while (tmp_x < x) {
			_actions.push_back(FORWARD);
			tmp_x++;
		}
	}
}

void	Ia::getPathEast(int x, int y)
{
	int	tmp_x = 0;
	int	tmp_y = 0;

	if (x > _x) {
		tmp_x = _x;
		while (tmp_x < x) {
			_actions.push_back(FORWARD);
			tmp_x++;
		}
	}
	if (y < _y) {
		tmp_y = _y;
		_actions.push_back(LEFT);
		while (tmp_y > y) {
			_actions.push_back(FORWARD);
			tmp_y--;
		}
	}
	else if (y > _y) {
		tmp_y = y;
		_actions.push_back(RIGHT);
		while (tmp_y < y) {
			_actions.push_back(FORWARD);
			tmp_y++;
		}
	}
}

void	Ia::getPathWest(int x, int y)
{
	int	tmp_x = 0;
	int	tmp_y = 0;

	if (x < _x) {
		tmp_x = _x;
		while (tmp_x > x) {
			_actions.push_back(FORWARD);
			tmp_x--;
		}
	}
	if (y < _y) {
		tmp_y = _y;
		_actions.push_back(LEFT);
		while (tmp_y > y) {
			_actions.push_back(FORWARD);
			tmp_y--;
		}
	}
	else if (y > _y) {
		tmp_y = y;
		_actions.push_back(RIGHT);
		while (tmp_y < y) {
			_actions.push_back(FORWARD);
			tmp_y++;
		}
	}
}

void	Ia::getPathSouth(int x, int y)
{
	int	tmp_y = 0;
	int	tmp_x = 0;
	
	if (_y < y) {
		tmp_y = _y;
		while (tmp_y < y) {
			_actions.push_back(FORWARD);
			tmp_y++;
		}
	}
	if (x < _x) {
		tmp_x = _x;
		_actions.push_back(LEFT);
		while (tmp_x > x) {
			_actions.push_back(FORWARD);
			tmp_x--;
		}
	}
	else if (x > _x) {
		tmp_x = x;
		_actions.push_back(RIGHT);
		while (tmp_x < x) {
			_actions.push_back(FORWARD);
			tmp_x++;
		}
	}
}
