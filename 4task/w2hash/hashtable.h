#pragma once
#include "node.h"
#include "stdafx.h"
#include "rndarray.h"
//����� ���-�������
class hashtable
{
//��������� �� ������ �������, ������� ������� � ����� �������
	//�� ����� head � _current
private:
	node* head;
	void Delete(node* del);//������������ � �����������
public:
	hashtable();//����������� ����������� �������� ��������� ���������� � ����� �������
	void Add(int key_value, int array_index);//������� � ��������� ������ � �������
	void Find(int key_value);//����� �������� �� ��������, ����� �������������� �������� � �������
	void PrintList();//����� ������� �� �����
	~hashtable();//����������� ������
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
				cout << "������� �� ��������� " << key_value << " ��������� ��� �������� " << temp->index << endl;
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