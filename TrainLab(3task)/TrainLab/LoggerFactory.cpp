#include "stdafx.h"
#include "LoggerFactory.h"

ILogger* LoggerFactory::Create(LoggerType type)
{
	switch (type)
	{
	case Console:
		return new ConsoleLogger();
	case File:
		return new FileLogger("log.txt");
	default: 
		throw new exception("Type doesn't support");
	}
}
