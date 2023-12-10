#ifndef CellDisplay_cpp
#define CellDisplay_cpp
#include "CellDisplay.h"
#include <typeinfo>

char CellDisplay::display(Cell &cell) const
{
    auto trapEvent = dynamic_cast<Trap *>(cell.get_event());
    auto teleportEvent = dynamic_cast<Teleport *>(cell.get_event());
    auto healingSpotEvent = dynamic_cast<HealingSpot *>(cell.get_event());
    if (cell.get_player_presence())
        return 'P';
    if (cell.getVisited() && cell.get_event())
    {
        if (trapEvent)
            return 'T';
        if (teleportEvent)
            return 'W';
        if (healingSpotEvent)
            return 'H';
    }
    else if (!cell.getVisited() && cell.get_event())
        return 'E';
    else if (cell.get_pass())
        return 'o';
    return '#';
}

#endif