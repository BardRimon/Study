// Лаб6_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");

	int n, m, c, max = 0, column = 0;
	cout << "Input N: ";
	cin >> n;
	cout << "\nInput M: ";
	cin >> m;
	cout << endl;

	srand((unsigned)time(0));
	//создаём массив из n указателей по m
	int** A = new int* [n];
	int** prow = A;
	while (prow - A < n)
	{
		*prow = new int[m];
		int* pi = *prow;
		int* pend = pi + m;
		while (pi < pend) {
			*pi = rand() % 10;
			pi++;
		}
		prow++;
	}

	// выводим массив в консоль
	prow = A;
	while (prow - A < n)
	{
		int* pi = *prow;
		int* pend = pi + m;
		while (pi < pend)
		{
			cout << *pi << " ";
			pi++;
		}
		cout << endl;
		prow++;
	}


	prow = A;
	int* pi = *prow;
	int i = 0;
	while (i < m)
	{
		c = 0;
		for (prow = A; prow - A < n; prow++)
		{
			//int* pi = *prow;
			pi = *prow;

			pi += i;
			if (*pi == 0)
			{
				c++;
			}
		}
		if (c > max)
		{
			max = c;
			column = i;
		}
		i++;
	}


	cout << endl << "В колонке " << column + 1;
	cout << " Наибольшее число 0 равное " << max << endl;

	int a, b, index;
	for (prow = A; prow - A < n / 2; prow++)
	{	
		index = prow - A;
		int* pi1 = A[index] + column; 
		int* pi2 = A[n - 1 - index] + column;
		int temp = *pi1;
		*pi1 = *pi2;
		*pi2 = temp;


		

	}

	cout << "массив с инверсированным столбцом" << endl;

	prow = A;
	while (prow - A < n)
	{
		int* pi = *prow;
		int* pend = pi + m;
		while (pi < pend)
		{
			cout << *pi << " ";
			pi++;
		}
		cout << endl;
		prow++;
	}

}

