#include "stdafx.h"
#include "train.h"


train::train()
{
	_current = NULL;
}

train::~train()
{
}

void train::Add(int value)//получает случайное число дл€ создани€ списка
{
	node* temp;//вспомогательные указатели при создании
	node* p;
	_current = (node*)malloc(sizeof(node));//выдел€ем пам€ть под 1ый элмент
	_current->light = rand() % 2;//заполн€ем значение 0 ил 1
	_current->next = _current;//в оба направлени€ первый элемент указывает сам на себ€
	_current->prev = _current;
	for (int i = 1; i < value; i++)//первый элемент создан, добавл€ем оставшиес€
	{
		temp = (node*)malloc(sizeof(node));//пам€ть под следующий элемент
		p = _current->next;//запоминаем указатель на следующий элемент
		_current->next = temp;//текущий элемент вперед указывает на новый
		temp->light = rand() % 2;//устанавливаем значение
		temp->next = p;//новый элемент вперед указывает на следующий
		temp->prev = _current;//новый элемент назад указывает на текущий
		p->prev = temp;//следующий элемет назад указывает на новый
		_current = temp;//новый элемент становитс€ текущим
	}
}

void train::Print()
{
	int count = Count();
	while (count-- > 0)
	{
		cout << _current->light << ",";
		_current = _current->next;
	}
	cout << endl;
}

void train::testPrint()
{
	cout << _current->light << ",";
	_current = _current->next;
}

int train::Count()
{
	if (_current == NULL)
	{
		return 0;
	}
	int counter = 0,steps=0;
	_current->light = !_current->light; 
	bool startLight = _current->light;
	while(true)
	{
		_current = _current->next;
		steps++;
		if (_current->light==startLight)
		{
			_current->light = !startLight;
			for (int j = 0; j < steps; j++)
			{
				_current=_current->prev;
				counter++;
			}
			if (_current->light!=startLight)
			{
				return counter;
			}
			else
			{
				steps = 0; counter = 0;
			}
		}
	}
}
