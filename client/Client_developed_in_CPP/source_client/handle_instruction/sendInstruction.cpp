//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// sendInstruction.cpp
//

#include "Client.hpp"

void		Client::sendInstruction()
{
	dprintf(_socket->fd, "%s\n", _answerReceived);
}
