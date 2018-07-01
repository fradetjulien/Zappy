//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// client.cpp
//

#include <ctime>
#include "../../include_client/client.hpp"

Client::Client(int ac, char **av)
	: _abscissa(0), _orderly(0), _host("127.0.0.1")
{
	if (ac < 7 || isWriteArguments(av) != 0) {
		helpClient();
	}
    _mode = PLV;
	_isAlreadySend = 0;
	_ia = std::make_unique<Ia>();
    _ia->initPlayer();
	_step[0] = std::bind(&Client::contactServer, this);
	_step[1] = std::bind(&Client::remainingPlaces, this);
	_step[2] = std::bind(&Client::worldDimension, this);
	_step[3] = std::bind(&Client::execute_ia, this);
    _execute[LOOK] = std::bind(&Client::execute_look, this);
    _execute[MOVE] = std::bind(&Client::execute_move, this);
    _execute[PPO] = std::bind(&Client::execute_ppo, this);
    _execute[PLV] = std::bind(&Client::execute_plv, this);
    _execute[INV] = std::bind(&Client::execute_inventory, this);
    _send[LOOK] = std::bind(&Client::send_look, this);
    _send[MOVE] = std::bind(&Client::send_move, this);
    _send[PPO] = std::bind(&Client::send_ppo, this);
    _send[PLV] = std::bind(&Client::send_plv, this);
    _send[INV] = std::bind(&Client::send_inventory, this);
    _cmdSend = false;
    _readCmd = false;
    _moveDone = false;
}

Client::~Client()
{
}

void Client::send_inventory()
{
    sendInstruction("Inventory");
    _cmdSend = true;
}

void Client::send_look()
{
    sendInstruction("Look");
    _cmdSend = true;
}

void Client::send_move()
{
    static std::size_t move = 0;
    std::string tmp = _ia->doActions(move);

    if (tmp == "stop") {
        _moveDone = true;
        _mode = PLV;
        std::string takeObj = "Take "  + _ia->getPriority();
        sendInstruction(takeObj.c_str());
        move = 0;
    }
    else {
        sendInstruction(tmp.c_str());
        move += 1;
    }
    _cmdSend = true;
}

void Client::send_ppo()
{
    std::string tmp = "ppo";
    sendInstruction(tmp.c_str());
    _cmdSend = true;
}

void Client::send_plv()
{
    std::string tmp = "plv " + _team;

    sendInstruction(tmp.c_str());
    _cmdSend = true;
}

void	Client::execute_ia()
{
    if (!_cmdSend) {
        _send[_mode]();
    }
    else if (_readCmd) {
        _execute[_mode]();
        _cmdSend = false;
    }
}

void    Client::execute_look()
{
    _ia->parseLook(_answerReceived);
    _ia->pathFinding();
    _mode = MOVE;
    _readCmd = false;
}

void Client::execute_move()
{
    _readCmd = false;
}

void Client::execute_ppo()
{
    _ia->handlePpo(_answerReceived);
    _mode = INV;
    _readCmd = false;
}

void Client::execute_plv()
{
    if (!_moveDone) {
        _ia->handlePlv(_answerReceived);
        _mode = PPO;
    }
    _moveDone = false;
    _readCmd = false;
}

void Client::execute_inventory()
{
    _ia->parseInventory(_answerReceived);
    _mode = LOOK;
    _readCmd = false;
}


