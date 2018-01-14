#pragma once
#include "ConsoleLogger.h"
#include "FileLogger.h"

enum LoggerType {File, Console};

class LoggerFactory
{
public:
	ILogger* Create(LoggerType type);
};

