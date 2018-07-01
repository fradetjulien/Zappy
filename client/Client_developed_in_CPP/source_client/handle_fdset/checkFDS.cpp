//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// checkFDS.cpp
//

#include "../../include_client/client.hpp"

void			Client::whichStep()
{
    if (_isAlreadySend == 0 && isWelcome() == 0)
		_step[_isAlreadySend]();
    else if (_isAlreadySend != 0)
		_step[_isAlreadySend]();
}

int			Client::checkFDS()
{
	for (int i = 0; i < (_fd + 1); i++) {
		if (FD_ISSET(_fd, &_read)) {
            if (_cmdSend || _isAlreadySend < 3)
			    getInstruction();
			whichStep();
		}
	}
	return (0);
}
