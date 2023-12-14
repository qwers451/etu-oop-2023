#ifndef LossLogger_h
#define LossLogger_h
#include "Logger.h"

class LossLogger: public Logger{
private:
    std::pair<int, int> cell_coords;
public:
    LossLogger(std::pair<int, int> cell_coords): cell_coords(cell_coords){}

    std::string log_to_str();

    ~LossLogger() = default;
};

#endif 