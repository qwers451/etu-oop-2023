#ifndef MessageHandler_h
#define MessageHandler_h
#include "Logger.h"



class MessageHandler{
private:
    std::vector<Logger*> log_messages;
public:
    MessageHandler(std::vector<Logger*> log_messages): log_messages(log_messages){}

    friend std::ostream& operator<<(std::ostream& os, const MessageHandler& msg_handler);

    void msg_update(Logger* msg);

    ~MessageHandler() = default;
};

#endif