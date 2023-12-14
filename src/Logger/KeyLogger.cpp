#ifndef KeyLogger_cpp
#define KeyLogger_cpp
#include "KeyLogger.h"

std::string KeyLogger::log_to_str(){
    std::stringstream log_view;
    log_view << "-----------------KeyLog-----------------\n";
    log_view << "Key: " << key_log.first;
    log_view << " | Command: " << key_commands::commandToString.at(key_log.second) << '\n';
    return log_view.str();
}


#endif 