#ifndef Trap_h
#define Trap_h
#include "PlayerEvents.h"

class Trap : public PlayerEvents
{
public:
    Trap(int value, Player &player) : PlayerEvents(value, player) {}

    void event_trigger();

    ~Trap() = default;
};

#endif