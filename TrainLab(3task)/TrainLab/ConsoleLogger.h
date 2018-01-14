#pragma once
#include "ILogger.h"

class ConsoleLogger: public ILogger
{
public:
	virtual void Information(string message);
	virtual void Warning(string message);
	virtual void Error(string message);
};

