#ifndef FieldEvents_h
#define FieldEvents_h
#include "Event.h"
#include "../Field/Field.h"

class FieldEvents : public Event
{
public:
    FieldEvents(std::pair<int, int> new_loc, Field *field, Player &player, Observer &eventObserver) : new_loc(new_loc), field(field), player(player), eventObserver(eventObserver) {}

    virtual void event_trigger() = 0;

    virtual void notifyEventObserver(std::string msg) = 0;

    ~FieldEvents() = default;

protected:
    std::pair<int, int> new_loc;
    Field *field;
    Player &player;
    Observer &eventObserver;
};

#endif