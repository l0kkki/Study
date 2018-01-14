#include "stdafx.h"
#include "FileLogger.h"


FileLogger::FileLogger(string fileName)
{
	_fileName = fileName;
	ofstream output;
}

void FileLogger::Information(string message)
{
	
	output.open(_fileName,std::ios::app);
	if (output.is_open())
	{
		output << message << std::endl;
	}
	//TODO: create log to file with name _fileName
}

void FileLogger::Warning(string message)
{
	output.open(_fileName, std::ios::app);
	if (output.is_open())
	{
		output << message << std::endl;
	}
	//TODO: create log to file
}

void FileLogger::Error(string message)
{
	output.open(_fileName, std::ios::app);
	if (output.is_open())
	{
		output << message << std::endl;
	}
	//TODO: create log to file
}

FileLogger::~FileLogger()
{
	output.close();
	//TODO: free memory
}
