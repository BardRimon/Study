// lab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//На основе таблицы, содержащей следующую информацию студентах :
//<фамилия>, <имя>, <отчество>, <пол>, <возраст>, <курс> (в фамилии,
//    имени и отчестве - не более 12 букв, пол указывается буквами М и Ж,
//    возраст - целое от 16 - 35, курс - целое от 1 - 5), написать программу, которая
//    вводит эту информацию и выводит на экран номер курса, на котором
//    наибольший процент мужчин.

//---------------------------------------------------------------------------



#include <iostream>
using namespace std;

struct Student {
    char lastName[13];
    char firstName[13];
    char patronymic[13];
    char sex;
    int age;
    int course;
};

void input(Student& s) {
    cout << "Фамилия: ";
    cin >> s.lastName;
    cout << "Имя: ";
    cin >> s.firstName;
    cout << "Отчество: ";
    cin >> s.patronymic;
    cout << "Пол (M/F): ";
    cin >> s.sex;
    cout << "Возраст: ";
    cin >> s.age;
    cout << "Курс: ";
    cin >> s.course;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество студентов: ";
    cin >> n;

    Student* students = new Student[n];
    for (int i = 0; i < n; ++i) {
        input(students[i]);
    }

    int totalCourses = 5;
    int totalStudents[5] = { 0 }; // Индексы 0-4 соответствуют курсам 1-5
    int maleCount[5] = { 0 };

    for (int i = 0; i < n; ++i) {
        int course = students[i].course;
        if (course < 1 || course > 5) {
            cout << "Некорректный курс у студента " << students[i].lastName << endl;
            continue;
        }
        totalStudents[course - 1]++;
        if (toupper(students[i].sex) == 'M') {
            maleCount[course - 1]++;
        }
    }

    double maxPercent = -1.0;
    int maxCourse = -1;
    for (int i = 0; i < 5; ++i) {
        if (totalStudents[i] == 0) {
            continue; // Избегаем деления на ноль
        }
        double percent = (maleCount[i] / static_cast<double>(totalStudents[i])) * 100;
        if (percent > maxPercent) {
            maxPercent = percent;
            maxCourse = i + 1; // Курс 1-5
        }
    }

    if (maxCourse == -1) {
        cout << "Нет студентов или все курсы пусты." << endl;
    }
    else {
        cout << "Курс с наибольшим процентом мужчин: " << maxCourse << endl;
    }

    delete[] students;
    return 0;
}












// ---------------------------------------------------------------------------------------
//#include <iostream>
//using namespace std;
//
//
//struct Table {
//    char last_name[13];
//    char first_name[13];
//    char patronymic_name[13];
//    char sex;
//    int age;
//    int course;
//
//};
//
//
//void input(Table &T) {
//    cout << "last name: ";
//    cin >> T.last_name;
//    cout << "first_name: ";
//    cin >> T.first_name;
//    cout << "patronymic_name: ";
//    cin >> T.patronymic_name;
//    cout << "sex: ";
//    cin >> T.sex;
//    cout << "age: ";
//    cin >> T.age;
//    cout << "course: ";
//    cin >> T.course;
//}
//
////bool is_male(Table& T) {
////    return T.sex == 'М'; // Убедитесь, что 'М' — кириллическая заглавная буква
////}
//
//
////int is_man(Table T) {
////    int count = 0;
////
////    if (T.sex == 'М') {
////        count = 1;
////    }
////    return count;
////}
//
//
//
////void sort(Table& T) {
////    for () {
////        for () {
////            if T.
////        }
////    }
////
////
////
////}
////
////
////void BubbleSort(vector<int>& values) {
////    for (size_t idx_i = 0; idx_i + 1 < values.size(); ++idx_i) {
////        for (size_t idx_j = 0; idx_j + 1 < values.size() - idx_i; ++idx_j) {
////            if (values[idx_j + 1] < values[idx_j]) {
////                swap(values[idx_j], values[idx_j + 1]);
////            }
////        }
////    }
////}
//
//
//int main()
//{
//
//    setlocale(LC_ALL, "Ru");
//
//    Table* list;
//    Table* male_list;
//
//    int n, i;
//    double* mass_value; //Объявление указателя на массив стоимости
//    setlocale(LC_ALL, "");
//    cout << "Введите количество сущностей:";
//    cin >> n;
//
//
//
//
//    list = new Table[n]; //Динамическое выделение памяти под на массив товаров
//    //Заполнение массива товаров с клавиатуры
//
//
//    for (i = 0; i < n; i++)
//        input(list[i]); //Вызов функции ввода товара с клавиатуры
//
//    Table* list_men;
//    int counter = 0;
//    for (i = 0; i < n; i++) {
//        if (list[i].sex == 'M')
//            counter++;
//    }
//    cout << counter;
//
//    male_list = new Table[counter];
//    int j = 0;
//    for (i = 0; i < n; i++) {
//        if (list[i].sex == 'M') {
//            male_list[j] = list[i];
//            j++;
//            //cout << "pupu pu " <<male_list[j].age << "\n";
//        }
//    }
//    int c = 0;
//    int c_max = 0;
//    int index;
//    n = j;
//    cout << "check";
//
//    for (i = 0; i < n + 1; i++) {
//        cout << male_list[i].course << endl;
//    }
//
//    for (i = 0; i < n; i++) {
//        c = 0;
//        for (j = 0; j < n;) {
//            if (male_list[i].course == male_list[j].course) {
//                c++;
//            }
//        }
//        if (c > c_max) {
//            c_max = c;
//            index = i;
//        }
//    }
//
//    cout << male_list[index].course;
//
//
//
//
//
//}
// 





//struct Student {
//    char fio[255];
//    int age;
//    long long int num_zach;
//
//};
//
//void example() {
//    Student* ZFIML_01_24;
//    Student Newbie;
//    Student* Novichok;
//
//    Novichok = new (Student);
//
//
//    ZFIML_01_24 = new Student[20];
//    std::cin >> Novichok->fio;
//
//
//
//
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
