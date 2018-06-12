//
// Created by simon_f on 12/06/18.
//

#include "server.h"

int main(int ac, char **av)
{
	(void)ac;
	if (server(av) == -1)
		return 84;
	return 0;
}
