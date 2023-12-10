#ifndef KeyParser_h
#define KeyParser_h
#include <vector>
#include <map>
#include "../Enum.h"
#include <fstream>
#include <sstream>

class KeyParser
{
private:
    std::map<char, COMMAND> keyDict;

    std::fstream file;

public:
    KeyParser(const char *filename);

    std::map<char, COMMAND> getKeyDict() const;

    ~KeyParser();
};

#endif