#ifndef IFieldGen_h
#define IFieldGen_h
#include "../Field.h"
#include "../../Game/Player.h"

class IFieldGen
{
public:
    virtual Field *create_field(Player &player) = 0;

    virtual ~IFieldGen() = default;
};

#endif