#ifndef GameObserver_cpp
#define GameObserver_cpp
#include "GameObserver.h"

void GameObserver::update(std::string msg)
{
    mvprintw(0, 0, "%s\n", msg.c_str());
    refresh();
}

#endif