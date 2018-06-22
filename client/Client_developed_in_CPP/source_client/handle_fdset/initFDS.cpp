//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// initFDS.cpp
//

#include "../../include_client/client.hpp"

void		Client::initFDS(fd_set *read, struct timeval *time)
{
	FD_ZERO(read);
	FD_SET(_fd, read);
	time->tv_sec = 0;
	time->tv_usec = 50;
}
