// hw2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "list1way.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int yes=0,number=0,choise=1;
	cout << "Создать список? 1 - да, 0 выход" << endl;
	cin >> yes;
	if (!yes)
		return 0;
	list1way list;
	cout << "Введите первый элемент" << endl;
	cin >> number;
	list.Init(number);
	cout << "Что дальше?" << endl;
	cout << "1. Добавить элемент в список после текущего" << endl;
	cout << "2. Удалить текущий элемент" << endl;
	cout << "3. Вперед по списку" << endl;
	cout << "4. Вернуться в начало списка" << endl;
	cout << "5. Вывод текущего элемента" << endl;
	cout << "6. Печать списка" << endl;
	cout << "7. Удалить 1ый элемент списка" << endl;
	cout << "8. Длина списка" << endl;
	cout << "0. Закончить работу" << endl;
	while (choise!=0)
	{
		cout << endl;
		list.ShowCurrent();
		cout << "Введите пункт меню" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "Введите значение" << endl;
			cin >> number;
			list.Add(number);
			break;
		case 2:
			list.ClearCurrent();
			break;
		case 3:
			list.Move();
			break;
		case 4:
			list.MoveToHead();
			break;
		case 5:
			list.ShowCurrent();
			break;
		case 6:
			list.PrintList();
			break;
		case 7:
			list.DeleteHead();
			break;
		case 8:
			list.ListLenthg();
			break;
		case 0:
		default:
			break;
		}
		
	}

    return 0;
}

