//
// Created by torres_l on 29/06/18.
//

#include "guiClient.hpp"

void GuiClient::algoGui()
{
    if (!_cmdSend) {
        _send[_mode]();
    }
    else if (_readCmd) {
        _execute[_mode]();
        _cmdSend = false;
    }
}

void GuiClient::execute_res()
{
    _gui->parseTitle(_answerReceived, false);
    if (_gui->getActualPos().size() - 1 == _ppo) {
        _ppo = 0;
        _mode = PPO;
        _gui->resetActualPos();
    }
    else
        _ppo++;
    _readCmd = false;
}

void GuiClient::execute_map()
{
    _gui->parseTitle(_answerReceived, true);
    if (_mapY == _orderly - 1 && _mapX == _abscissa - 1) {
        _mapX = 0;
        _mapY = 0;
        _mode = PPO;
    }
    if (_mapX + 1  > _abscissa - 1) {
        _mapY++;
        _mapX = 0;
    }
    else
        _mapX++;
    _readCmd = false;
}

void GuiClient::execute_ppo()
{
    if (_answerReceived == "ko\n") {
        _gui->drawMap();
        _gui->displayWin();
        _gui->clearWin();
        _gui->drawMap();
        _ppo = 0;
        if (!_gui->getActualPos().empty())
            _mode = RES;
    }
    else {
        _gui->parsePlayer(_answerReceived);
        _ppo++;
    }
    _readCmd = false;
}

void GuiClient::send_map()
{
    std::string tmp = "bct " + std::to_string(_mapX) + " " + std::to_string(_mapY);

    sendInstruction(tmp.c_str());
    _cmdSend = true;
}

void GuiClient::send_ppo()
{
    std::string tmp = "ppo " + std::to_string(_ppo);
    sendInstruction(tmp.c_str());
    _cmdSend = true;
}

void GuiClient::send_res()
{
    std::vector<std::pair<size_t, size_t>> tmpVec = _gui->getActualPos();
    std::string tmp = "bct " + std::to_string(tmpVec[_ppo].first) + " " + std::to_string(tmpVec[_ppo].second);
    sendInstruction(tmp.c_str());
    _cmdSend = true;
}