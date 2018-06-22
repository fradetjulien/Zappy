//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// sendInstruction.cpp
//

#include "../../include_client/client.hpp"

void		Client::sendInstruction()
{
	dprintf(_fd, "%s\n", _answerReceived.c_str());
}
