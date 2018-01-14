#pragma once
#include "stdafx.h"

class ILogger
{
public:
	virtual void Information(string message) = 0;
	virtual void Warning(string message) = 0;
	virtual void Error(string message) = 0;
};
