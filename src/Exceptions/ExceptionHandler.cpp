#ifndef ExceptionHanler_cpp
#define ExceptionHanler_cpp
#include "ExceptionHandler.h"

size_t ExceptionHandler::checkForException()
{
	try
	{
		this->converter.setKeyMap(KeyParser(cfg).getKeyDict());
	}
	catch (std::invalid_argument)
	{
		std::cerr << "dublicat\n";
		return 1;
	}
	catch (ExitGame)
	{
		std::cerr << "not bind\n";
		return 1;
	}
	catch (std::out_of_range)
	{
		std::cerr << "key error\n";
		return 1;
	}
	return 0;
}

#endif