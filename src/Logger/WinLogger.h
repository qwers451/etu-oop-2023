#ifndef WinLogger_h
#define WinLogger_h
#include "Logger.h"

class WinLogger: public Logger{
private:
    std::vector<int> player_stats;
public:
    WinLogger(std::vector<int> player_stats): player_stats(player_stats){}

    std::string log_to_str();

    ~WinLogger() = default;
};

#endif