#ifndef ChangeConfig_cpp
#define ChangeConfig_cpp
#include "ChangeConfig.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

void ChangeConfig::changeConfigFile(const char *filename)
{
    std::string cmd = "/bin/nano " + static_cast<std::string>(filename);
    system(cmd.c_str());
}

#endif