// w2hash.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "rndarray.h"
#include "hashtable.h"

int HashFunction(int arg, int key_value)//���������� ������� �� �������
{
	return key_value%arg;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 0, hash_arg = 0,a=0;
	cout << "������� ����������� ������� " << endl;
	cin >> size;
	rndarray A(size);
	A.Create();
	A.Print();
	cout << "������� �������� ��� ���-�������" << endl;
	cin >> hash_arg;
	//���������� ����� ���-������� � ���-�������� ������������ ������� �� ������� �� �����, ����� ����� ������ �����
	//������� ������ ������� hashtable
	//������ ������� �������� ������
	//������� ������� ��� ������, ���� ���������� �������� �� �����
	hashtable* array_A = new hashtable[hash_arg];
	int key = 0;
	for (int i = 0; i < size; i++)
	{
		key=HashFunction(hash_arg, A.Value(i));//��������� ���� ��� ������� �������� �������
		array_A[key].Add(A.Value(i), i);//�������� � ��������������� ������ �������� � ������
	}
	//���������� ���������� ��� �������
	/*for (int i = 0; i < hash_arg; i++)
	{
		array_A[i].PrintList();
	}*/
	cout << "����� ������� �����?" << endl;
	int what_find = 0;
	cin >> what_find;
	key = HashFunction(hash_arg, what_find);//��������� ���� ��� ��������, ������� ���� �����
	array_A[key].Find(what_find);//������� �� ����� �������, �� ������� ����������� ������ ������� � �������� �������
	cin >> a;
	return 0;
}

