// Лаб3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    char a, b, c;
    int length, height;
    int i, j;
    int type;
    cout << "chose 1, 2, or 3 type: " << endl;
    cin >> type;

    switch (type)
    {
    case 1:
        cout << "Insert parameters:" << endl << "Cube's simbol is ... " << endl;
        cin >> a;
        cout << "length = " << endl;
        cin >> length;
        cout << "and height = " << endl;
        cin >> height;
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < length; j++)
            {
                cout << a;
            }
            cout << endl;
        }
        break;
    case 2:
        cout << "triangle's simbol is ... " << endl;
        cin >> b;
        cout << "height of triangle is ... " << endl;
        cin >> height;

        for (i = 1; i <= height; i++)
        {
            for (j = 1; j <= i; j++)
            {
                cout << b;
            }
            cout << endl;
        }
        break;
    case 3:
        cout << "hyperboloid's simbol is ..." << endl;
        cin >> c;
        cout << "height of griangle is ... " << endl;
        cin >> height;

        length = height / 2 + 1;
        for (i = 1; i <= height; i++)
        {

            for (j = 1; j <= length; j++)
            {
                cout << c;
            }
            if (i <= height / 2)
            {
                length--;
            }
            else
            {
                length++;
            }
            cout << endl;
        }
        break;
    }    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
