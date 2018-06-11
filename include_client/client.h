/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client.h
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>

# define LOCALHOST	"127.0.0.1"

typedef struct			s_socket
{
	int			fd;
	socklen_t		len;
}				t_socket;

typedef struct			s_client
{
	char			*port;
	char			*team;
	char			*host;
	fd_set			*read;
	t_socket		*socket;
}				t_client;

t_socket			*init_client(t_client *client);
void				free_client(t_client client);
void				help_client(char *binary);
int				launch_client(t_client *client);
int				isWriteArguments(char **av);
int				isHostname(char *host);
int				isPort(char *port);

#endif /* !CLIENT_H_ */
