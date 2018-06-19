//
// Created by simon_f on 12/06/18.
//

#include <time.h>
#include "server.h"

int main(int ac, char **av)
{
		srand(time(NULL));
		(void)ac;
        if (verification_args(av) == -1)
                return (84);
        if (loop_server(ac, av) == -1)
                return 84;
        return 0;
}
