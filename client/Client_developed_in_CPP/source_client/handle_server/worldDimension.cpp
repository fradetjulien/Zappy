//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// worldDimension.cpp
//

#include "Client.hpp"

int			Client::worldDimension()
{
	int		i = -1;
	
	_abscissa = atoi(_answerReceived);
	while (_answerReceived && answerReceived[++i] != ' ');
	std::string	tmp = new &_answerReceived[i];
	_orderly = atoi(tmp);
	if (_abscissa < 1 || _orderly < 1)
		return (-1);
	else
		dprintf(1, "%d %d\n", _abscissa, _orderly);
	return (0);
}
