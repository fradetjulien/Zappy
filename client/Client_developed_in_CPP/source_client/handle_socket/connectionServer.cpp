//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// connectionServer.cpp
//

#include "Client.hpp"

int		Client::connectionServer()
{
	int	error = 0;

	if (initSocket("TCP") == -1) {
		std::cerr << "Can not initialize the connection"
			  << std::endl;
		return (-1);
	}
	_socket->s.sin_family = AF_INET;
	_socket->s.sin_addr.s_addr = inet_addr(_host);
	_socket->s.sin_port = htons(atoi(_port));
	error = connect(_socket->fd,
	(const struct sockaddr *)&_socket->s,
	sizeof(_socket->s));
	if (error == -1) {
		std::cerr << "Can not establish connection"
			  << std::endl;
		closeSocket();
		return (-1);
	}
	return (0);
}
