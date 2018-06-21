//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// initSocket.cpp
//

#include "Client.hpp"

int		Client::initSocket(const char *protocol)
{
	_protocol = getprotobyname(protocol);
	if (_protocol == nullptr)
		return (-1);
	_socket->fd = socket(AF_INET, SOCK_STREAM,
	_protocol->p_proto);
	if (_socket->fd == -1)
		return (-1);
	return (0);
}
