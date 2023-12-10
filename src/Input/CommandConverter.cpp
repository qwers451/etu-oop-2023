#ifndef CommandConverter_cpp
#define CommandConverter_cpp
#include "CommandConverter.h"

namespace key_map
{
    std::map<char, COMMAND> keyDict;
}

bool CommandConverter::hasCommand(char symbol) const
{
    auto pos = this->keyDict.find(symbol);
    return pos != this->keyDict.end() ? true : false;
}

COMMAND CommandConverter::toCommand(char symbol) const
{
    if (!hasCommand(symbol))
        return COMMAND::NONE;
    return this->keyDict.at(symbol);
}

void CommandConverter::setKeyMap(std::map<char, COMMAND> keyDict)
{
    this->keyDict = keyDict;
}

#endif