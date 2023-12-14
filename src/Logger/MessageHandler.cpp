#ifndef MessageHandler_cpp
#define MessageHandler_cpp
#include "MessageHandler.h"
#include <typeinfo>

std::ostream& operator<<(std::ostream& os, const MessageHandler& msg_handler){
    for(int i = 0; i < msg_handler.log_messages.size(); ++i){
        os << msg_handler.log_messages[i]->log_to_str();
    }
    return os;
}

void MessageHandler::msg_update(Logger* msg){
    log_messages.push_back(msg);
}

#endif