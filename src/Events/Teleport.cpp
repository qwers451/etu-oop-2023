#ifndef Teleport_cpp
#define Teleport_cpp
#include "Teleport.h"

void Teleport::notifyEventObserver(std::string msg)
{
    this->eventObserver.update(msg);
}

void Teleport::event_trigger()
{
    this->notifyEventObserver("tp triggered\n");
    if (this->player.get_intelligence() >= 15)
        this->field->set_new_loc(this->new_loc.first, this->new_loc.second);
    else
        this->field->set_new_loc(this->field->get_start().first, this->field->get_start().second);
}

#endif