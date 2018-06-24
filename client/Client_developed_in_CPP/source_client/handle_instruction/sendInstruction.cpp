//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// sendInstruction.cpp
//

#include "../../include_client/client.hpp"

void		Client::sendInstruction(const char *instruction)
{
	std::cout << "SENDING : [" << instruction << "]" << std::endl;
	dprintf(_fd, "%s\n", instruction);
}
