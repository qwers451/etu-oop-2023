#ifndef FrameLimiter_cpp
#define FrameLimiter_cpp
#include "FrameLimiter.h"

using framePeriod = std::chrono::duration<long long, std::ratio<1, 30>>;

void FrameLimiter::frameLimiter(DrawField &fieldDisplay)
{
    auto prev = std::chrono::high_resolution_clock::now();
    auto current = prev;
    auto difference = current - prev;
    while (difference < framePeriod{1})
    {
        current = std::chrono::high_resolution_clock::now();
        difference = current - prev;
    }
    fieldDisplay.drawField();
    using hr_duration = std::chrono::high_resolution_clock::duration;
    prev = std::chrono::time_point_cast<hr_duration>(prev + framePeriod{1});
    difference = current - prev;
}

#endif
