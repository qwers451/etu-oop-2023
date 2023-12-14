#ifndef LogOutputManager_h
#define LogOutputManager_h
#include "../Logger/MessageHandler.h"
#include "FileHandler.h"

class LogOutputManager{
private:
    MessageHandler& msg_handler;
public:
    LogOutputManager(MessageHandler& msg_handler): msg_handler(msg_handler) {}

    void output(char option);

    ~LogOutputManager() = default;
};

#endif