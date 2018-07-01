//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// getInstruction.cpp
//

#include "../../include_client/client.hpp"
#include "../../include_client/exception.hpp"

int		Client::getInstruction()
{
	FILE	*fd = fdopen(_fd, "r");
	std::size_t len = 0;
	char *tmp = nullptr;

    _answerReceived.clear();
	getline(&tmp, &len, fd);
	_answerReceived.assign(tmp);
	if (_answerReceived.empty() || _answerReceived == "dead")
		throw MyError("Ia dead");
    if (_isAlreadySend == 3)
	    _readCmd = true;
	return (0);
}
