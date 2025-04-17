// Лаб6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int iter;
    int n, m, i, j, * A, * p, counter = 0, column = 0, c;
    


    cout << "Подсчёт через i (Введите 1) или через указатели (Введите 2)" << endl;
    cin >> iter;
    switch (iter)
    {
    case 1:

        
        cout << "Введите n и m:" << endl << "n = ";
        cin >> n;
        cout << "m = ";
        cin >> m;
        cout << endl;

        A = new int[n * m];
        srand((unsigned)time(0));
        // наполнение матрицы из рандомными числами
        for (p = A; p - A < n * m; p++)
        {
            *p = rand() % 10; // 10 было взято для того, чтобы вероятность получить 0 в столбце была выше
        }
        // вывод в консоль
        cout << endl << "Ввод массива A[n][m]:" << endl << endl;
        for (i = 0, p = A; i < n * m; i++, p++)
        {
            if (i % m == 0)
            {
                cout << endl;
            }
            cout.width(2);
            cout << *p;
        }
        cout << endl;

        for (i = 0; i < m; i++)
        {
            c = 0;
            for (j = 0; j < n; j++, p++)
            {
                if (A[j * m + i] == 0)
                {
                    c++;
                }

            }
            if (counter < c)
            {
                counter = c;
                column = i;
            }
        }

        cout << endl << "С наибольшим числом нулей = " << counter << " колонка №" << column + 1 << endl;

        for (i = 0; i < n / 2; i++)
        {
            //cout << endl << A[i * m + column] << A[(n - 1 - i) * m + column];
            j = A[i * m + column];
            A[i * m + column] = A[(n - 1 - i) * m + column];
            A[(n - 1 - i) * m + column] = j;

            //cout << endl << A[i * m + column] << A[(n - 1 - i) * m + column];

        }



        cout << endl << "Обработанная матрица: " << endl;
        for (i = 0, p = A; i < n * m; i++, p++)
        {
            if (i % m == 0)
            {
                cout << endl;
            }
            cout.width(2);
            cout << *p;
        }


        delete[] A;

    case 2:
        cout << "-";
    }
    
    

}

