#pragma once
#include "stdafx.h"
//������ ������� ������ �������� ������ �� ���������� ����������
class rndarray
{
private:
	int* _array;
	int size;
public:
	rndarray()
	{
		_array = NULL;
	}
	//����������� �����������
	rndarray(int value)
	{
		_array = new int[value];
		size = value;
	}
	//�������� ������ ��� �������
	int Size()
	{
		if (_array == NULL)
			return 0;
		return size;
	}
	//���������� ������ �������
	void Print()
	{
		cout << "���������� �������:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}
	//����� ������� �� �����
	void Create()
	{
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			_array[i] = rand() % 100;
		}
	}
	//���������� ������� ���������� ����������
	int Value(int index)
	{
		return _array[index];
	}
	//���������� ��������� �������� � ������������ � ��������
	~rndarray()
	{
		delete[] _array;
	}
	//����������� ������
};

