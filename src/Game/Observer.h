#ifndef Observer_h
#define Observer_h
#include <string>
#include <ncurses.h>

class Observer
{
public:
    virtual void update(std::string msg) = 0;
};

#endif