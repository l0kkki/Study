#pragma once
#include "stdafx.h"
#include "node.h"

class list1way
{
private:

	node* head;

public:

	list1way()
	{
		cout << "Работа конструктора" << endl;
		head = NULL;		
	}

	void Add(int value)
	{
		if (head==NULL)
		{
			head = new node;
			head->data = value;
			head->next = NULL;
		}
		else
		{
			node* temp = new node;
			temp->data = value;
			temp->next = head;
			head = temp;
		}		
	}

	void Delete(node* del)
	{			
		if (head!=NULL)
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
					if(temp->next==del)
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
	
	void Insert(node* ins,int value)
	{
		if (head != NULL)
		{
			node* temp = head;
			if (ins == head)
			{
				node* p = new node;
				p->data = value;
				temp = head->next;
				head->next = p;
				p->next = temp;
			}
			else
			{
				while (temp != NULL)
				{
					if (temp == ins)
					{
						node* p = new node;
						p->data = value;
						p->next = temp->next;
						temp->next = p;
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

	void PrintList()
	{
		node* temp=head;
		cout << "Полный список ";
		while(temp!=NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	node* Find(int value)
	{
		if (head!=NULL)
		{
			node* temp = head;
			while (temp != NULL)
			{
				if (temp->data == value)
					return temp;
				else
					temp = temp->next;				
			}			
		}
		return NULL;		
	}

	~list1way()
	{
		cout << "Работа деструктора" << endl;
		if (head!=NULL)
		{
			while (head!=NULL)
			{
				Delete(head);
			}			
		}
	}
};

