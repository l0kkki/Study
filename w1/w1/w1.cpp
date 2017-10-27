// w1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int generated = rand()%10+1;//генерируем количество элементов для примера от 1 до 10
	train someTrain;//создаем объект класса
	cout <<"Сгенерировано число - "<< generated<<endl;//генерируем количество элементов
	someTrain.Add(generated);//создаем наш список
	for (int i = 0; i < generated; i++)//для наглядности распечатаем наш список
	{
		someTrain.testPrint();
	}
	cout << endl;
	cout << endl;
	cout << "Результат подсчета - " << someTrain.Count() << endl;//вызываем функцию подсчета с помощью алгоритма обхода
	someTrain.Print();//изменились значения, так как для подсчета мы меняли значения элементов в списке
	system("pause");
    return 0;
}

