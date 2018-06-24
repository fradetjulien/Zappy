/*
** EPITECH PROJECT, 2018
** init_serv
** File description:
** init_serv
*/

#include "server.h"

int	create_socket(int port)
{
	struct sockaddr_in s_in;
	struct protoent *pe = getprotobyname("TCP");

	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr.s_addr = INADDR_ANY;
	int fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (fd == -1)
		return (-1);
	if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1) {
		close(fd);
		perror("bind");
		return (-1);
	}
	if (listen(fd, 42) == -1) {
		close(fd);
		perror("listen");
		return (-1);
	}
	return (fd);
}

void init_server(server *server, char **av, int ac)
{
	server->port = fill_port(ac, av);
	server->fd = create_socket(server->port);
	server->nb_player = 0;
	server->client = NULL;
	server->nbMax = fill_nb_players(ac, av);
	server->width = fill_width(ac, av);
	server->height = fill_height(ac, av);
	server->frequency = fill_frequency(ac, av);
	server->team = fill_name_teams(ac, av);
	server->client = malloc(sizeof(struct Client) * 100);
	if (server->client == NULL)
		exit(84);
	server->fd_max = server->fd;
	server->actual = 0;
	if (server->frequency == 0 || server->width == 0 || server->height == 0)
		exit(84);
	init_command(server);
	init_function_command(server);
	server->map = init_map(server);
	server->look = NULL;
	server->eggs = NULL;
}

void	socket_client(server *server, fd_set *rdfs)
{
	struct sockaddr_in csin = {0};
	size_t sinsize = sizeof csin;
	int csock = accept(server->fd, (struct sockaddr*)&csin,
			   (unsigned int *)&sinsize);
	server->fd_max = csock > server->fd_max ? csock : server->fd_max;
	FD_SET(csock, rdfs);
	client c = {csock, NULL, 0, server->nb_player, 1,
		    rand() % server->width, rand() % server->height, NORTH, NULL, 1260, NULL};
	c.inventory = init_inventory();
	server->client[server->actual] = c;
	server->actual++;
	server->nb_player++;
	dprintf(csock, "WELCOME\n");
}

static void server_client(server *server, struct timeval *tv,
			  fd_set rdfs, char *buf)
{
	int i = 0;
	int s;
	
	for (i = 0; i < server->actual; i++)
		FD_SET(server->client[i].fd, &rdfs);
	s = select(server->fd_max + 1, &rdfs, NULL, NULL, tv);
	if (s == -1) {
		perror("select");
		exit(84);
	}
	if (s != 0) {
		if (FD_ISSET(server->fd, &rdfs))
			socket_client(server, &rdfs);
		else
			manage_client(server, rdfs, &buf);
	}
	if (s == 0) {
		if (execute_cmd(server) == 2)
			exit(0);
		manage_time(server);
	}
}

int	loop_server(int ac, char **av)
{
	server server;
	fd_set rdfs;
	graphics graph;
	struct timeval	tv;
	char *buf = malloc(sizeof(char) * 4096);

	if (buf == NULL)
		return (84);
	init_server(&server, av, ac);
	if (server.fd == -1)
		return -1;
	printf("Port : %d\n", server.port);
	init_sdl(&graph);
	while (1) {
		FD_ZERO(&rdfs);
		FD_SET(STDIN_FILENO, &rdfs);
		FD_SET(server.fd, &rdfs);
		tv.tv_sec = 0;
		tv.tv_usec = 1000000 / server.frequency;
		server_client(&server, &tv, rdfs, buf);
		if (draw_map(&graph, &server) == 1) {
			destroy_sdl_elements(&graph);
			break;
		}
	}
	return (0);
}
