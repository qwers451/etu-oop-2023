#ifndef Event_h
#define Event_h
#include "../Game/Player.h"
#include "../Game/GameObserver.h"

class Event
{
public:
    virtual void event_trigger() = 0;

    virtual ~Event() = default;
};

#endif