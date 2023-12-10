#ifndef CellDisplay_h
#define CellDisplay_h
#include "Cell.h"
#include "../Events/Event.h"
#include "../Events/Teleport.h"
#include "../Events/Trap.h"
#include "../Events/HealingSpot.h"

class CellDisplay
{
public:
    char display(Cell &cell) const;
};

#endif