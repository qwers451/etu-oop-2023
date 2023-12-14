#ifndef GameLogger_h
#define GameLogger_h
#include "Logger.h"

class GameLogger: public Logger{
private:
    std::pair<int, int> field_size;
    std::pair<int, int> starting_position;
public:
    GameLogger(std::pair<int, int> field_size, std::pair<int, int> starting_position):
    field_size(field_size), starting_position(starting_position) {}

    std::string log_to_str();

    ~GameLogger() = default;
};

#endif