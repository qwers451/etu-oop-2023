#ifndef FrameLimiter_h
#define FrameLimiter_h
#include <chrono>
#include "Field/DrawField.h"

class FrameLimiter
{
public:
    void frameLimiter(DrawField &fieldDisplay);
};

#endif