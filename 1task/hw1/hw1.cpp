// hw1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

class A
{
public:
	A()
	{
		cout << "����������� ������ �" << endl;
	}
	A(bool overload)
	{
		cout << "����������� ������ � �������������"<<endl;
	}
	virtual ~A()
	{
		cout << "������ ����������� ������ �"<<endl;
	}
};
class B: public A
{
public:
	B()
	{
		cout << "����������� ������ B" << endl;
	}
	B(bool overload)
	{
		cout << "����������� ������ B �������������" << endl;
	}
	~B()
	{
		cout << "������ ����������� ������ B" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	A* a1=new B;
	delete a1;
	cout << endl;
	A a2=new A;
	cout << endl;
	B b=new B;
	cout << endl;
	return 0;
}

