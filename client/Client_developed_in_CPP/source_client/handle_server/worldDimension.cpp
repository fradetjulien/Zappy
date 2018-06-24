//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// worldDimension.cpp
//

#include "../../include_client/client.hpp"
#include "../../include_client/exception.hpp"

void			Client::worldDimension()
{
	int		i = -1;

	_abscissa = atoi(_answerReceived.c_str());
	while (!_answerReceived.empty() && _answerReceived[++i] != ' ');
	std::string	tmp = &_answerReceived[i];
	_orderly = atoi(tmp.c_str());
	if (_abscissa < 1 || _orderly < 1)
		throw MyError("ici");
	else
		dprintf(1, "%d %d\n", _abscissa, _orderly);
	_isAlreadySend = 3;
}
