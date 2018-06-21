#include "server.h"

void init_command(server *server)
{
    server->cmd[0] = "forward";
    server->cmd[1] = "right";
    server->cmd[2] = "left";
    server->cmd[3] = "look";
    server->cmd[4] = "inventory";
    server->cmd[5] = "broadcast";
    server->cmd[6] = "connect_nbr";
    server->cmd[7] = "fork";
    server->cmd[8] = "eject";
    server->cmd[9] = "take";
    server->cmd[10] = "incantation";
    server->cmd[11] = "msz";
    server->cmd[12] = "bct";
    server->cmd[13] = "mct";
    server->cmd[14] = "tna";
    server->cmd[15] = "ppo";
    server->cmd[16] = "plv";
    server->cmd[17] = "pin";
    server->cmd[18] = "sgt";
    server->cmd[19] = "sst";
    server->cmd[20] = "pdi";
    server->cmd[21] = NULL;
}

void init_function_command(server *server)
{
    server->command[0] = &forward;
    server->command[1] = &right;
    server->command[2] = &left;
    server->command[3] = &look;
    server->command[4] = &inventory;
    server->command[5] = &broadcast;
    server->command[6] = &connect_nbr;
    server->command[7] = &_fork;
    server->command[8] = &eject;
    server->command[9] = &take;
    server->command[10] = &incantation;
    server->command[11] = &msz;
    server->command[12] = &bct;
    server->command[13] = &mct;
    server->command[14] = &tna;
    server->command[15] = &ppo;
    server->command[16] = &plv;
    server->command[17] = &pin;
    server->command[18] = &sgt;
    server->command[19] = &sst;
    server->command[20] = &pdi;
    server->command[21] = NULL;
}
