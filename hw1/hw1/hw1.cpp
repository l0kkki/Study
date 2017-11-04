// hw1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

class A
{
public:
	A()
	{
		cout << "Конструктор класса А" << endl;
	}
	A(bool overload)
	{
		cout << "Конструктор класса А перегруженный"<<endl;
	}
	virtual ~A()
	{
		cout << "Работа деструктора класса А"<<endl;
	}
};
class B: public A
{
public:
	B()
	{
		cout << "Конструктор класса B" << endl;
	}
	B(bool overload)
	{
		cout << "Конструктор класса B перегруженный" << endl;
	}
	~B()
	{
		cout << "Работа деструктора класса B" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	A* a1=new B;
	cout << endl;
	A a2=new A;
	cout << endl;
	B b=new B;
	cout << endl;
	return 0;
}

