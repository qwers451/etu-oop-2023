#ifndef MessageMediator_h
#define MessageMediator_h
#include <vector>
#include <variant>
#include "KeyLogger.h"
#include "GameLogger.h"
#include "WinLogger.h"
#include "LossLogger.h"


namespace msg_mediator{
    extern std::vector<std::variant<GameLogger, KeyLogger, WinLogger, LossLogger>> msg_logs;
};

#endif 