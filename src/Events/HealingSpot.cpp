#ifndef HealingSpot_cpp
#define HealingSpot_cpp
#include "HealingSpot.h"
#include "../Game/Classes.h"

void HealingSpot::event_trigger()
{
    CLASS className = this->player.get_class();
    if (this->player.get_hp() == Classes(className).hP)
    {
    }
    else
        this->player.set_health(this->player.get_hp() + this->value);
}

#endif
