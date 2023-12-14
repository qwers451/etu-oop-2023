#ifndef GameLogger_cpp
#define GameLogger_cpp
#include "GameLogger.h"

std::string GameLogger::log_to_str(){
    std::stringstream log_view;
    log_view << "-----------------GameLog----------------\n";
    log_view << "Height: " << field_size.first << " | Width: " << field_size.second << '\n';
    log_view << "Starting X coordinate: " << starting_position.first << "\nStarting Y coordinates: " << starting_position.second << '\n';
    return log_view.str();
}

#endif