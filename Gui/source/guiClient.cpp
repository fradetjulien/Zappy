//
// Created by torres_l on 29/06/18.
//

#include "guiClient.hpp"

GuiClient::GuiClient(char **av)
{
    _isAlreadySend = 0;
    _port.assign(av[1]);
    _team.assign(av[2]);
    _host.assign(av[3]);
    _step[0] = std::bind(&GuiClient::contactServer, this);
    _step[1] = std::bind(&GuiClient::remainingPlaces, this);
    _step[2] = std::bind(&GuiClient::worldDimension, this);
    _step[3] = std::bind(&GuiClient::algoGui, this);
    _execute[MAP] = std::bind(&GuiClient::execute_map, this);
    _execute[PPO] = std::bind(&GuiClient::execute_ppo, this);
    _execute[RES] = std::bind(&GuiClient::execute_res, this);
    _send[MAP] = std::bind(&GuiClient::send_map, this);
    _send[PPO] = std::bind(&GuiClient::send_ppo, this);
    _send[RES] = std::bind(&GuiClient::send_res, this);
    _cmdSend = false;
    _readCmd = false;
    _reset = false;
    _mode = MAP;
    _mapX = 0;
    _mapY = 0;
    _ppo = 0;
}

void GuiClient::launchClient()
{
    _fdMax = _fd + 1;
    while (42) {
        if (_gui != nullptr)
            _gui->handleEvent();
        initFds();
        if (select(_fdMax, &_read, nullptr, nullptr, &_time) == -1)
            throw MyError("Select error");
        checkFds();
        if (_gui != nullptr)
            _gui->displayWin();
    }
}

void GuiClient::initFds()
{
    FD_ZERO(&_read);
    FD_SET(_fd, &_read);
    _time.tv_sec = 0;
    _time.tv_usec = 50;
}

void GuiClient::checkFds()
{
    for (int i = 0; i < (_fd + 1); i++) {
        if (FD_ISSET(_fd, &_read)) {
            if (_cmdSend || _isAlreadySend < 3)
                getInstructions();
            whichStep();
        }
    }
}

void GuiClient::getInstructions()
{
    FILE	*fd = fdopen(_fd, "r");
    std::size_t len = 0;
    char *tmp = nullptr;

    _answerReceived.clear();
    getline(&tmp, &len, fd);
    _answerReceived.assign(tmp);
    if (_answerReceived.empty())
        throw MyError("Getline error");
    if (_isAlreadySend == 3)
        _readCmd = true;
}

void GuiClient::contactServer()
{
    sendInstruction(_team.c_str());
    printInstruction(_answerReceived.c_str());
    printInstruction(_team.c_str());
    _isAlreadySend = 1;
}

void GuiClient::remainingPlaces()
{
    if (atoi(_answerReceived.c_str()) >= 1) {
        printInstruction(_answerReceived.c_str());
        _isAlreadySend = 2;
        return ;
    }
    throw MyError("Server full");
}

void GuiClient::worldDimension()
{
    int		i = -1;

    _abscissa = atoi(_answerReceived.c_str());
    while (!_answerReceived.empty() && _answerReceived[++i] != ' ');
    std::string	tmp = &_answerReceived[i];
    _orderly = atoi(tmp.c_str());
    if (_abscissa < 1 || _orderly < 1)
        throw MyError("ici");
    else
        dprintf(1, "%d %d\n", _abscissa, _orderly);
    _isAlreadySend = 3;
    _gui = std::make_unique<Gui>(_abscissa, _orderly);
}

void GuiClient::sendInstruction(const char *instruction)
{
    dprintf(_fd, "%s\n", instruction);
}

void GuiClient::printInstruction(const char *instruction)
{
    dprintf(1, "%s\n", instruction);
}

int GuiClient::isWelcome()
{
    if (_answerReceived.empty()) {
        return (-1);
    }
    else if (_answerReceived == "WELCOME") {
        return (-1);
    }
    else {
        return (0);
    }
}
void GuiClient::whichStep()
{
    if (_isAlreadySend == 0 && isWelcome() == 0)
        _step[_isAlreadySend]();
    else if (_isAlreadySend != 0)
        _step[_isAlreadySend]();
}
