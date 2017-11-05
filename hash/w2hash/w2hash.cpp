// w2hash.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "rndarray.h"
#include "hashtable.h"

int HashFunction(int arg, int key_value)//Возвращает остаток от деления
{
	return key_value%arg;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 0, hash_arg = 0;
	cout << "Введите размерность массива " << endl;
	cin >> size;
	rndarray A(size);
	A.Create();
	A.Print();
	cout << "Введите аргумент для хеш-функции" << endl;
	cin >> hash_arg;
	//Количество полей хеш-таблицы с хеш-функцией возвращающей остаток от деления на число, будет равно самому числу
	//создаем массив классов hashtable
	//индекс массива является ключом
	//элемент массива это список, куда помещаются значения по ключу
	hashtable* array_A = new hashtable[hash_arg];
	int key = 0;
	for (int i = 0; i < size; i++)
	{
		key=HashFunction(hash_arg, A.Value(i));//вычесляем ключ для каждого элемента массива
		array_A[key].Add(A.Value(i), i);//помещаем в соответствующий список значение и индекс
	}
	//Распечатка полученной хеш таблицы
	//for (int i = 0; i < hash_arg; i++)
	//{
	//	array_A[i].PrintList();
	//}
	cout << "Какой элемент найти?" << endl;
	int what_find = 0;
	cin >> what_find;
	key = HashFunction(hash_arg, what_find);//вычесляем ключ для элемента, который надо найти
	array_A[key].Find(what_find);//выводим на экран индексы, на которых встречаются данный элемент в исходном массиве
	return 0;
}

