#ifndef ExitGame_h
#define ExitGame_h
#include <stdexcept>
#include <exception>

struct ExitGame : public std::exception
{
    int value;
    ExitGame(int value) : value(value) {}
};

#endif