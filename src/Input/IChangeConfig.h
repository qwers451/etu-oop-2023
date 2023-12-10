#ifndef IChangeConfig_h
#define IChangeConfig_h

class IChangeConfig
{
public:
    virtual void changeConfigFile(const char *filename) = 0;
};

#endif