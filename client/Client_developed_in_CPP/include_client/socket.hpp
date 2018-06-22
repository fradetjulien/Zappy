//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// socket.hpp
//

#ifndef SOCKET_HPP_
# define SOCKET_HPP_

#include "client.hpp"

class				Socket
{
private:
	int			fd;
	struct sockaddr_in	s;
	socklen_t		len;
public:
	Socket();
	~Socket();
};

#endif /* !SOCKET_HPP_ */
