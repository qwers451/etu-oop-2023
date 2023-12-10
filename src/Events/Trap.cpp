#ifndef Trap_cpp
#define Trap_cpp
#include "Trap.h"

void Trap::event_trigger()
{
    if (this->player.get_finesse() < 15)
    {
        if (this->player.get_hp() - this->value < 0)
        {
            this->player.set_health(0);
        }
        this->player.set_health(this->player.get_hp() - this->value);
    }
}

#endif