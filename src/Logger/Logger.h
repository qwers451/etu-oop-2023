#ifndef Logger_h
#define Logger_h
#include "../Enum.h"
#include <utility>

class Logger{
public:
    virtual std::string log_to_str() = 0;

    virtual ~Logger() = default;
};

#endif
