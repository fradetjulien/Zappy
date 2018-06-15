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
}

void	socket_client(int *max, server *server)
{
	client *client = malloc(sizeof(struct Client));
	struct sockaddr_storage	r;
	socklen_t	len;

	memset(client, 0, sizeof(*client));
      	len = sizeof(r);
	client->socket = accept(server->fd, (struct sockaddr *)&r, &len);
	if (client->socket == -1) {
		perror("accept");
		exit(84);
	}
	FD_SET(client->socket, &server->server);
	if (client->socket > *max)
		*max = client->socket;
	init_client(client, server);
	client = add_client(client);
	dprintf(client->socket, "WELCOME\n");
	server->client = client;
}

int	loop_server(int ac, char **av)
{
	server server;
	init_server(&server, av, ac);
	FD_ZERO(&server.server);
	FD_SET(server.fd, &server.server);
	fd_set rdfs;
	int	max = server.fd;
	int s;

	FD_ZERO(&rdfs);
	if (server.fd == -1)
		return -1;
	printf("Port : %d\n", server.port);
	while (1) {
		rdfs = server.server;
		s = select(max + 1, &rdfs, NULL, NULL, NULL);
		if (s) {
			for (int i = 0; i <= max; i++) {
				if (FD_ISSET(i, &rdfs)) {
					if (i == server.fd) {
						socket_client(&max, &server);
						server.nb_player++;
					}
					else
						if (manage_cmd(&server, i) == -1)
							return -1;
				}
			}
		}
	}
        return (0);
}
