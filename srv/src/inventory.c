//
// Created by simon_f on 20/06/18.
//

#include "server.h"

t_rsrc *init_inventory()
{
    t_rsrc *inventory = malloc(sizeof(t_rsrc));

    if (inventory == NULL)
        return NULL;
    inventory->nb_linemate = 0;
    inventory->nb_deraumere = 0;
    inventory->nb_sibur = 0;
    inventory->nb_mendiane = 0;
    inventory->nb_phiras = 0;
    inventory->nb_thystame = 0;
    inventory->nb_food = 0;
    return (inventory);
}
