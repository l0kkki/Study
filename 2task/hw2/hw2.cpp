// hw2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "list1way.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0;
	list1way lst;
	for (int i = 0; i < 10; i++)
	{
		lst.Add(i);
	}
	lst.PrintList();
	node* Find_res = lst.Find(5);
	lst.Delete(Find_res);
	lst.PrintList();
	Find_res = lst.Find(6);
	lst.Insert(Find_res, 5);
	lst.PrintList();
	cin >> a;
    return 0;
}

