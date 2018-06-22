//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// main.cpp
//

#include "../include_client/client.hpp"
#include "../include_client/exception.hpp"

int		main(int ac, char **av)
{
    try {
        Client	newClient(ac, av);
        newClient.connectionServer();
        newClient.launchClient();
    }
    catch (const MyError &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
	return (0);
}
