#ifndef Observer_h
#define Observer_h
#include <string>
#include <ncurses.h>
#include "../Enum.h"

class Observer{
public:
    virtual void update(std::string msg) = 0;

    virtual std::vector<std::string> getMsgVector() const = 0;

    virtual void updateFieldDisplay(WINDOW* fieldDisplay, std::stringstream output) = 0;
};

#endif