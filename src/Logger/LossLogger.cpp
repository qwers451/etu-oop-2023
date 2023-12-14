#ifndef LossLogger_cpp
#define LossLogger_cpp
#include "LossLogger.h"

std::string LossLogger::log_to_str(){
    std::stringstream log_view;
    log_view << "-----------------LossLog----------------\n";
    log_view << "X coordinate: " << cell_coords.first << " | Y coordinate: " << cell_coords.second << '\n';
    return log_view.str(); 
}

#endif