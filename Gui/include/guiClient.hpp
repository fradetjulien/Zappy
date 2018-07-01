//
// Created by torres_l on 29/06/18.
//

#ifndef PSU_ZAPPY_2017_GUICLIENT_HPP
#define PSU_ZAPPY_2017_GUICLIENT_HPP

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <functional>
#include <unordered_map>
#include "gui.hpp"
#include "exception.hpp"

enum Mode {
    MAP,
    PPO,
    RES
};

class GuiClient {
public:
    GuiClient(char **);
    ~GuiClient() = default;

    void connectionServer();
    void launchClient();

private:
    struct protoent		*_protocol;
    std::string		_port;
    std::string		_team;
    std::string		_answerReceived;
    int			_abscissa;
    int			_orderly;
    int _mapX;
    int _mapY;
    std::size_t _ppo;
    std::string		_host;
    fd_set			_read;
    int			_fd;
    int         _fdMax;
    struct sockaddr_in	_s;
    socklen_t		_len;
    struct timeval  _time;
    std::size_t _isAlreadySend;
    std::unique_ptr<Gui> _gui;
    std::unordered_map<std::size_t, std::function<void()>>	_step;
    std::unordered_map<Mode, std::function<void()>> _execute;
    std::unordered_map<Mode, std::function<void()>> _send;
    Mode _mode;
    bool _cmdSend;
    bool    _readCmd;
    bool _reset;

    int isWelcome();
    void whichStep();
    void initFds();
    void checkFds();
    void getInstructions();
    void contactServer();
    void remainingPlaces();
    void worldDimension();
    void sendInstruction(const char *);
    void printInstruction(const char *);
    void initSocket();
    void closeSocket();
    void algoGui();
    void execute_res();
    void execute_map();
    void execute_ppo();
    void send_map();
    void send_ppo();
    void send_res();
};

#endif //PSU_ZAPPY_2017_GUICLIENT_HPP
