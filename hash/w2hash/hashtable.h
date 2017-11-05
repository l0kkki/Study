#pragma once
#include "node.h"
#include "stdafx.h"
#include "rndarray.h"
// ласс хеш-таблицы
class hashtable
{
//”казатели на голову таблицы, текущий элемент и длину таблицы 
private:
	node* head;
	node* _current;
	int length;
	void DeleteHead();//используетс€ в деструкторе
public:
	hashtable();//стандартный конструктор занул€ет значаени€ указателей и длины таблицы
	void Add(int key_value, int array_index);//создает и добавл€ет запись в таблицу
	void Find(int key_value);//поиск элемента по значению, вывод местоположени€ элемента в массиве
	void PrintList();//вывод таблицы на экран
	~hashtable();//освобождает пам€ть
};

hashtable::hashtable()
{
	head = NULL;
	_current = NULL;
	length = 0;
}

void hashtable::Add(int key_value, int array_index)
{
	if(head==NULL)
	{
		head = new node;
		head->index = array_index;
		head->value = key_value;
		head->next = NULL;
		_current = head;
		length++;
	}
	else
	{
		node* temp = new node;
		_current->next = temp;
		temp->index = array_index;
		temp->value = key_value;
		temp->next = NULL;
		_current = temp;
		length++;
	}
}

void hashtable::Find(int key_value)
{
	_current = head;
	for (int i = 0; i < length; i++)
	{
		if (_current->value == key_value)
		{
			cout << "Ёлемент со значением " << key_value << " находитс€ под индексом " << _current->index<<endl;
		}
		_current = _current->next;
	}
}

void hashtable::PrintList()
{
	node* temp;
	temp = head;
	cout << "ѕолный список " << length << ": ";
	for (int i = 0; i < length; i++)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void hashtable::DeleteHead()
{
	node* temp;
	if (head->next == NULL)
	{
		delete head;
		length--;
		head = NULL;
	}
	else
	{
		temp = head->next;
		delete head;
		head = temp;;
		length--;
	}
}

hashtable::~hashtable()
{
	if (head != NULL)
	{
		for (int i = 0; i < length; i++)
		{
			DeleteHead();
		}
	}
}