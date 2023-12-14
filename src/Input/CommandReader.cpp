#ifndef CommandReader_cpp
#define CommandReader_cpp
#include "CommandReader.h"
#include <ncurses.h>

COMMAND CommandReader::read()
{
    char symbol = 0;
    symbol = getch();
    msg_handler.msg_update(new KeyLogger(std::make_pair(symbol, this->converter.toCommand(symbol))));
    return this->converter.toCommand(symbol);
}

#endif