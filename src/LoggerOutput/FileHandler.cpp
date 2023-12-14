#ifndef FileHandler_cpp
#define FileHandler_cpp
#include "FileHandler.h"

FileHandler::FileHandler(const char* filename, MessageHandler& msg_handler):
    filename(filename), msg_handler(msg_handler){
    file.open(filename);
    if(file.is_open()){
        file << msg_handler;
        file << "-----------------EndLog-----------------";
    }
    file.close();
}

FileHandler::~FileHandler(){
    if(file.is_open())
        file.close();
}
#endif