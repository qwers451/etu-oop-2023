#ifndef KeyLogger_h
#define KeyLogger_h
#include "Logger.h"

class KeyLogger: public Logger{
public:
    KeyLogger(std::pair<char, COMMAND> key_log): key_log(key_log) {}
    
    std::string log_to_str();
    
    std::pair<char, COMMAND> getKeyLog() const;

    ~KeyLogger() = default;
private:
    std::pair<char, COMMAND> key_log;
};

#endif 