#ifndef Teleport_h
#define Teleport_h
#include "FieldEvents.h"
#include <utility>

class Teleport : public FieldEvents
{
public:
    Teleport(std::pair<int, int> new_loc, Field *field, Player &player, Observer &eventObserver) : FieldEvents(new_loc, field, player, eventObserver) {}

    void event_trigger();

    void notifyEventObserver(std::string msg);

    ~Teleport() = default;
};

#endif