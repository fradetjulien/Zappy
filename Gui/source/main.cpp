//
// Created by torres_l on 29/06/18.
//

#include "guiClient.hpp"

int main(int ac, char **av)
{
    srand(time(NULL));
    try {
        GuiClient	newClient(av);
        newClient.connectionServer();
        newClient.launchClient();
    }
    catch (const MyError &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
