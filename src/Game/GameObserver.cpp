#ifndef GameObserver_cpp
#define GameObserver_cpp
#include "GameObserver.h"

void GameObserver::update(std::string msg){
    // msg_vector.push_back(msg);
    mvprintw(0, 0, "%s\n", msg.c_str());
    refresh();
}

std::vector<std::string> GameObserver::getMsgVector() const{
    return this->msg_vector;
}

void GameObserver::updateFieldDisplay(WINDOW* fieldDisplay, std::stringstream output){
    box(fieldDisplay, 0, 0);
    mvwprintw(fieldDisplay, 0, 1, "Game Field");
    mvwprintw(fieldDisplay, 3, 3, "%s", output.str().c_str());
    wrefresh(fieldDisplay);
}

#endif