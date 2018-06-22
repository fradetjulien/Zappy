//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// getInstruction.cpp
//

#include "Client.hpp"

int		Client::getInstruction()
{
	getline(_socket->fd, _answerReceived);
	if (_answerReceived == nullptr)
		return (-1);
	return (0);
}
