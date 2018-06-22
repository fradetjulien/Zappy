//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// helpClient.cpp
//

#include "../../include_client/client.hpp"
#include "../../include_client/exception.hpp"

void		Client::helpClient()
{
    throw MyError("USAGE: ./zappy_ai -p port -n name -h machine\n\tport\tis the port number\n\tname\tis the name of the team\n\tmachine\tis the name of the machine; localhost by default");
}
