#ifndef CommandReader_cpp
#define CommandReader_cpp
#include "CommandReader.h"
#include <ncurses.h>

COMMAND CommandReader::read()
{
    char symbol = 0;
    symbol = getch();
    return this->converter.toCommand(symbol);
}

#endif