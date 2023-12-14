#ifndef WinLogger_cpp
#define WinLogger_cpp
#include "WinLogger.h"

std::string WinLogger::log_to_str(){
    std::stringstream log_view;
    std::vector<std::string> stats_names = {"health", "strength", "finesse", 
    "intelligence", "exp", "money", "armor"};
    log_view << "-----------------WinLog-----------------\n";
    for(int i = 0; i < player_stats.size(); ++i){
        log_view << stats_names[i] << ": " << player_stats[i] << '\n';
    }
    return log_view.str();
}

#endif