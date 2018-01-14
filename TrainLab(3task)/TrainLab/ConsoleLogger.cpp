#include "stdafx.h"
#include "ConsoleLogger.h"

void ConsoleLogger::Information(string message)
{
	cout << "INFO: " << message.c_str() << endl;
}

void ConsoleLogger::Warning(string message)
{
	cout << "WARN: " << message.c_str() << endl;
}

void ConsoleLogger::Error(string message)
{
	cout << "ERR: " << message.c_str() << endl;
}
