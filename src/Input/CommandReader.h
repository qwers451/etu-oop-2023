#ifndef CommmandReader_h
#define CommmandReader_h
#include "ICommandReader.h"
#include "CommandConverter.h"
#include "../Logger/MessageHandler.h"
#include "../Logger/KeyLogger.h"


class CommandReader : public ICommandReader
{
private:
    CommandConverter &converter;
    MessageHandler& msg_handler;
public:
    CommandReader(CommandConverter& converter, MessageHandler& msg_handler): 
    converter(converter), msg_handler(msg_handler) {}

    COMMAND read();
};

#endif