#ifndef FileHandler_h
#define FileHandler_h
#include "../Logger/MessageHandler.h"
#include <fstream>

class FileHandler{
    std::ofstream file;
    const char* filename;
    MessageHandler& msg_handler;
public:
    FileHandler(const char* filename, MessageHandler& msg_handler);

    ~FileHandler();
};

#endif