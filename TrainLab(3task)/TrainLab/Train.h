#pragma once
#include "ILogger.h"
#include "Node.h"

class Train
{
	ILogger* _logger;
	Node* _current;
public:
	Train(ILogger* logger);
	~Train(); 
	void Add(bool light);
	void Print();
	int Count();
};

