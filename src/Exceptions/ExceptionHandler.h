#ifndef ExceptionHandler_h
#define ExceptionHandler_h
#include "../Input/CommandConverter.h"
#include "../Input/KeyParser.h"
#include "ExitGame.h"
#include <iostream>

class ExceptionHandler
{
private:
    CommandConverter &converter;

public:
    ExceptionHandler(CommandConverter &converter) : converter(converter) {}

    size_t checkForException();
};

#endif