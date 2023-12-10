#ifndef PlayerEvents_h
#define PlayerEvents_h
#include "Event.h"

class PlayerEvents : public Event
{
public:
    PlayerEvents(int value, Player &player) : value(value), player(player) {}

    virtual void event_trigger() = 0;

    virtual ~PlayerEvents() = default;

protected:
    int value;
    Player &player;
};

#endif