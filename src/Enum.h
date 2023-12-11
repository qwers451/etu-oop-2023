#ifndef Enum_h
#define Enum_h
#include <map>
#include <string>
#include <ncurses.h>

enum MOVEMENT
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum CLASS
{
    FIGHTER,
    SPION,
    PIRAT
};

enum class COMMAND
{
    MOVEUP,
    MOVEDOWN,
    MOVERIGHT,
    MOVELEFT,
    QUIT,
    NONE
};

static const char *cfg = "config.txt";

namespace key_commands
{
    static std::map<std::string, COMMAND> stringToCommand = {{"MOVEUP", COMMAND::MOVEUP}, {"MOVEDOWN", COMMAND::MOVEDOWN}, {"MOVERIGHT", COMMAND::MOVERIGHT}, {"MOVELEFT", COMMAND::MOVELEFT}, {"QUIT", COMMAND::QUIT}};
}

namespace key_map
{
    extern std::map<char, COMMAND> keyDict;
}

#endif