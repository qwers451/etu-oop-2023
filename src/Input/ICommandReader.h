#ifndef ICommandReader_h
#define ICommandReader_h
#include "../Enum.h"

class ICommandReader
{
public:
    virtual COMMAND read() = 0;
};

#endif