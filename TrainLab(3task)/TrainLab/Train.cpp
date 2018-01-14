#include "stdafx.h"
#include "Train.h"

Train::Train(ILogger* logger)
{
	_logger = logger;
	_current = NULL;
}


Train::~Train()
{

}

void Train::Add(bool Light)
{
	Node* node = new Node(Light);
	if (_current == NULL)
	{
		_current = node;
	}
	else
	{
		Node* Next = _current->Next;
		if (Next == NULL)
		{
			_current->Next = node;
			node->Prev = _current;
			node->Next = _current;
			_current->Prev = node;
		}
		else
		{
			_current->Next = node;
			Next->Prev = node;
			node->Prev = _current;
			node->Next = Next;
		}
	}
}

void Train::Print()
{
	int count = Count();
	while (count-- > 0)
	{
		cout << _current->Light << ",";
		_current = _current->Next;
	}
}

int Train::Count()
{
	if (_current == NULL)
	{
		_logger->Information("Train has no carriages");
		return 0;
	}
	int counter = 0, steps = 0;
	_current->Light = !_current->Light;
	bool startLight = _current->Light;
	while (true)
	{
		_current = _current->Next;
		steps++;
		if (_current->Light == startLight)
		{
			_current->Light = !startLight;
			for (int j = 0; j < steps; j++)
			{
				_current = _current->Prev;
				counter++;
			}
			if (_current->Light != startLight)
			{
				return counter;
			}
			else
			{
				steps = 0; counter = 0;
			}
		}
	}
	/*if (_current == NULL)
	{
		_logger->Information("Train has no carriages");
		return 0;
	}
	
	int counter = 1;
	bool startLight = _current->Light;
	while (true)
	{
		for (int forward = 0; forward < counter; forward++)
		{
			_current = _current->Next;
		}
		if (_current->Light == startLight)
		{
			_current->Light = !startLight;
			for (int ret = 0; ret < counter; ret++)
			{
				_current = _current->Prev;
			}
			if (_current->Light != startLight)
			{
				return counter;
			}
		}
		counter += 1;
	}*/
}
