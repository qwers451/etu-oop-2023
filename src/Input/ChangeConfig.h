#ifndef ChangeConfig_h
#define ChangeConfig_h
#include "IChangeConfig.h"
#include "../Enum.h"

class ChangeConfig : public IChangeConfig
{
public:
    void changeConfigFile(const char *filename);
};

#endif