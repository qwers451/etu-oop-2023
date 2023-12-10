#ifndef CommandConverter_h
#define CommandConverter_h
#include "../Enum.h"

class CommandConverter
{
private:
    std::map<char, COMMAND> keyDict;

public:

    bool hasCommand(char symbol) const;

    COMMAND toCommand(char symbol) const;

    void setKeyMap(std::map<char, COMMAND> keyDict);
};

#endif