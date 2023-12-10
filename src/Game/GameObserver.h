#ifndef GameObserver_h
#define GameObserver_h
#include "Observer.h"

class GameObserver : public Observer
{
public:
    void update(std::string obsMessage);
};

#endif