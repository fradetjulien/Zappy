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

int	server(char **av)
{
	struct sockaddr_in in_client;
	socklen_t in_size = sizeof(in_client);
	int     client_fd;
	int     port = atoi(av[1]);
	int     fd = create_socket(port);

	if (fd == -1)
		return -1;
	while (1) {
		client_fd = accept(fd, (struct sockaddr *) &in_client, &in_size);
		if (client_fd == -1) {
			close(fd);
			return (1);
		}
		dprintf(client_fd, "You are connected\n");
		pid_t pid = fork();
		if (pid == 0) {
			printf("Ouais");
		}
	}
        return (0);
}
