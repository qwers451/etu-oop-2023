#ifndef FieldGenerator_h
#define FieldGenerator_h
#include "IFieldGen.h"
#include "../../Events/Trap.h"
#include "../../Events/Teleport.h"
#include "../../Events/HealingSpot.h"

class FieldGenerator : public IFieldGen
{
public:
    FieldGenerator(int height, int width, Observer &eventObserver);

    Field *create_field(Player &player);

    ~FieldGenerator() = default;

private:
    int height;
    int width;
    Observer &eventObserver;
    Field new_field;
};

#endif