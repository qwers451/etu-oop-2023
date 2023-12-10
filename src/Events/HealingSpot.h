#ifndef HealingSpot_h
#define HealingSpot_h
#include "PlayerEvents.h"

class HealingSpot : public PlayerEvents
{
public:
    HealingSpot(int value, Player &player) : PlayerEvents(value, player) {}

    void event_trigger();

    ~HealingSpot() = default;
};

#endif