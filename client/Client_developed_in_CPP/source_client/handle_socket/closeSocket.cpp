//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// closeSocket.cpp
//

#include "Client.hpp"

int		Client::closeSocket()
{
	if (close(_socket->fd) == -1) {
		return (-1);
	}
	_socket->fd = -1;
	return (0);
}
