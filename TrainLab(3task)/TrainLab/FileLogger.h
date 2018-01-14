#pragma once
#include "ILogger.h"
#include <iostream>
#include <fstream>

class FileLogger: public ILogger
{
private:
	string _fileName;
	ofstream output;
public:
	virtual void Information(string message);
	virtual void Warning(string message);
	virtual void Error(string message);
	FileLogger(string fileName);
	virtual ~FileLogger();
};

