#pragma once
#include "stdafx.h"

class train
{
private:
	node* _current;//указатель на текущий элемент
public:
	train();
	~train();
	void Add(int value);
	void Print();
	void testPrint();
	int Count();
};

