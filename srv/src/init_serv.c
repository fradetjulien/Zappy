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
	server->port = fill_port(av);
    server->fd = create_socket(server->port);
	server->nb_player = 0;
    server->client = NULL;
	server->nbMax = fill_nb_players(ac, av);
	server->width = fill_width(av);
	server->height = fill_height(av);
	server->team = fill_name_teams(ac, av);
	server->client = malloc(sizeof(struct Client) * 10);
	server->fd_max = server->fd;
	server->actual = 0;
	init_command(server);
	init_function_command(server);
}

void	socket_client(server *server, fd_set *rdfs)
{
	struct sockaddr_in csin = {0};
    size_t sinsize = sizeof csin;
    int csock = accept(server->fd, (struct sockaddr*)&csin,
	(unsigned int *)&sinsize);
    server->fd_max = csock > server->fd_max ? csock : server->fd_max;
    FD_SET(csock, rdfs);
	client c = {csock, NULL, 0, server->actual, 1,
	rand() % server->width, rand() % server->height, NORTH};
	server->client[server->actual] = c;
	server->actual++;
	dprintf(csock, "WELCOME\n");
}

int	loop_server(int ac, char **av)
{
	server server;
	fd_set rdfs;
	struct timeval	tv;
	int	i;
	int	s;

	init_server(&server, av, ac);
	if (server.fd == -1)
		return -1;
	printf("Port : %d\n", server.port);
	while (1) {
		FD_ZERO(&rdfs);
		FD_SET(STDIN_FILENO, &rdfs);
		FD_SET(server.fd, &rdfs);
		for (i = 0; i < server.actual; i++)
		      FD_SET(server.client[i].fd, &rdfs);
		s = select(server.fd_max + 1, &rdfs, NULL, NULL, &tv);
		if (s == -1) {
			perror("select");
			return -1;
		}
		if (FD_ISSET(STDIN_FILENO, &rdfs))
			break;
	    else if (FD_ISSET(server.fd, &rdfs)) {
			socket_client(&server, &rdfs);
		}
		else {
			manage_client(&server, rdfs);
		}
	}
	return (0);
}
