//
// Created by torres_l on 29/06/18.
//

#include "guiClient.hpp"

void GuiClient::connectionServer()
{
    int	error = 0;

    initSocket();
    _s.sin_family = AF_INET;
    _s.sin_addr.s_addr = inet_addr(_host.c_str());
    _s.sin_port = htons(atoi(_port.c_str()));
    error = connect(_fd, (const struct sockaddr *)&_s, sizeof(_s));
    if (error == -1) {
        closeSocket();
        throw MyError("Can not establish connection");
    }
}

void GuiClient::initSocket()
{
    _protocol = getprotobyname("TCP");
    if (_protocol == nullptr)
        throw MyError("Can not initialize the connection");
    _fd = socket(AF_INET, SOCK_STREAM,
                 _protocol->p_proto);
    if (_fd == -1)
        throw MyError("Can not initialize the connection");
}

void GuiClient::closeSocket()
{
    if (close(_fd) == -1) {
        throw MyError("Close fd error");
    }
    _fd = -1;
}