#pragma once
#include "node.h"
#include "stdafx.h"
#include "rndarray.h"
//Класс хеш-таблицы
class hashtable
{
//Указатели на голову таблицы, текущий элемент и длину таблицы
	//не нужен head и _current
private:
	node* head;
	void Delete(node* del);//используется в деструкторе
public:
	hashtable();//стандартный конструктор зануляет значаения указателей и длины таблицы
	void Add(int key_value, int array_index);//создает и добавляет запись в таблицу
	void Find(int key_value);//поиск элемента по значению, вывод местоположения элемента в массиве
	void PrintList();//вывод таблицы на экран
	~hashtable();//освобождает память
};

hashtable::hashtable()
{
	head = NULL;
}

void hashtable::Add(int key_value, int array_index)
{
	if (head == NULL)
	{
		head = new node;
		head->value = key_value;
		head->index = array_index;
		head->next = NULL;
	}
	else
	{
		node* temp = new node;
		temp->value = key_value;
		temp->index = array_index;
		temp->next = head;
		head = temp;
	}
}

void hashtable::Find(int key_value)
{
	if (head != NULL)
	{
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->value == key_value)
			{
				cout << "Элемент со значением " << key_value << " находится под индексом " << temp->index << endl;
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

void hashtable::PrintList()
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void hashtable::Delete(node* del)
{
	if (head != NULL)
	{
		node* temp = head;
		if (del == head)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		else
		{
			while (temp != NULL)
			{
				if (temp->next == del)
				{
					temp->next = del->next;
					delete del;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
	}
}

hashtable::~hashtable()
{
	if (head != NULL)
	{
		while (head != NULL)
		{
			Delete(head);
		}
	}
}