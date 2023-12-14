#ifndef LogOutputManager_cpp
#define LogOutputManager_cpp
#include "LogOutputManager.h"
#include <iostream>

void LogOutputManager::output(char option){
    switch (option)
    {
    case '1':
        std::cout << msg_handler;
        std::cout << "-----------------EndLog-----------------\n";
        break;
    case '2':
        FileHandler("log.txt", msg_handler);
        break;
    case '3':
        std::cout << msg_handler;
        std::cout << "-----------------EndLog-----------------\n";
        FileHandler("log.txt", msg_handler);
        break;
    default:
        break;
    }
}

#endif