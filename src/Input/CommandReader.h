#ifndef CommmandReader_h
#define CommmandReader_h
#include "ICommandReader.h"
#include "CommandConverter.h"

class CommandReader : public ICommandReader
{
private:
    CommandConverter &converter;

public:
    CommandReader(CommandConverter &converter) : converter(converter) {}

    COMMAND read();
};

#endif