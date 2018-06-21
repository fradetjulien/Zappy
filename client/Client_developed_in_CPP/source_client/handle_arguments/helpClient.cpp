//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// helpClient.cpp
//

#include "Client.hpp"

void		Client::helpClient(char *binary)
{
	std::cout << "USAGE: " << binary << " -p port -n name"
		  << " -h machine\n" << "\tport\tis the port number\n"
		  << "\tname\tis the name of the team\n"
		  << "\tmachine\tis the name of the machine; "
		  << "localhost by default\n";
}
