#pragma once
#include "stdafx.h"
//Объект данного класса является массив со случайными значениями
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
	//Стандартный конструктор
	rndarray(int value)
	{
		_array = new int[value];
		size = value;
		cout << "Выделена память под массив размера " << size<<endl;
	}
	//Выделяет память для массива
	int Size()
	{
		if (_array == NULL)
			return 0;
		return size;
	}
	//Возвращает размер массива
	void Print()
	{
		cout << "Содержимое массива:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}
	//Вывод массива на экран
	void Create()
	{
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			_array[i] = rand() % 100;
		}
		cout << "Массив заполнен случайными значениями" << endl;
	}
	//Заполнение массива случайными значениями
	int Value(int index)
	{
		return _array[index];
	}
	//Возвращает значаение элемента в соответствии с индексом
	~rndarray()
	{
		delete[] _array;
		cout << "Работа деструктора, массив удален" << endl;
	}
	//Освобождаем память
};

