// лаб10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include <iostream>;
//#include <cstdlib>;
//#include <windows.h>;
// 
// 
// 
// 





#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <codecvt>
#include <windows.h>
#include <algorithm>

using namespace std;

struct StudentAcademics {
    wstring lastName;
    wstring firstName;
    wstring patronymic;
    int course;
    int physics;
    int math;
    int programming;
};

struct StudentPersonal {
    wstring lastName;
    wstring firstName;
    wstring patronymic;
    wchar_t gender;
    int birthYear;
};

struct StudentFull {
    StudentAcademics academics;
    StudentPersonal personal;

    StudentFull(StudentAcademics a, StudentPersonal p) : academics(a), personal(p) {}
};

wstring utf8_to_wstring(const string& str) {
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}

string removeCR(const string& str) {
    string result;
    for (char c : str) {
        if (c != '\r') {
            result += c;
        }
    }
    return result;
}

vector<StudentAcademics> readScores(const string& filename) {
    vector<StudentAcademics> students;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return students;
    }

    string line;
    while (getline(file, line)) {
        line = removeCR(line);
        stringstream ss(line);
        StudentAcademics s;
        string token;

        getline(ss, token, ','); s.lastName = utf8_to_wstring(token);
        getline(ss, token, ','); s.firstName = utf8_to_wstring(token);
        getline(ss, token, ','); s.patronymic = utf8_to_wstring(token);
        getline(ss, token, ','); s.course = stoi(token);
        getline(ss, token, ','); s.physics = stoi(token);
        getline(ss, token, ','); s.math = stoi(token);
        getline(ss, token, ','); s.programming = stoi(token);

        students.push_back(s);
    }

    return students;
}

vector<StudentPersonal> readPersonal(const string& filename) {
    vector<StudentPersonal> students;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return students;
    }

    string line;
    while (getline(file, line)) {
        line = removeCR(line);
        stringstream ss(line);
        StudentPersonal s;
        string token;

        getline(ss, token, ','); s.lastName = utf8_to_wstring(token);
        getline(ss, token, ','); s.firstName = utf8_to_wstring(token);
        getline(ss, token, ','); s.patronymic = utf8_to_wstring(token);
        getline(ss, token, ','); s.gender = utf8_to_wstring(token)[0];
        getline(ss, token, ','); s.birthYear = stoi(token);

        students.push_back(s);
    }

    return students;
}


void printStudent(const StudentFull& s) {
    wcout << s.academics.lastName << " "
        << s.academics.firstName << " "
        << s.academics.patronymic
        // Дополнительно можно вывести другие поля

        << " (Курс: " << s.academics.course << ")"
        << endl;
}



int main() {
    // Настройка кодировок
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    // Чтение данных
    auto academics = readScores("C:/Users/bardr/source/repos/Programming workshop/Лабы_по_cpp/лаб10/scores.csv");
    auto personal = readPersonal("C:/Users/bardr/source/repos/Programming workshop/Лабы_по_cpp/лаб10/students.csv");

    // Проверка чтения
    if (academics.empty() || personal.empty()) {
        cerr << "Ошибка: один из файлов не прочитан!" << endl;
        return 1;
    }

    // Объединение данных
    vector<StudentFull> students;
    size_t minSize = min(academics.size(), personal.size());

    for (size_t i = 0; i < minSize; ++i) {
        students.push_back({ academics[i], personal[i] });
    }

    // Вывод информации
    wcout << L"Список студентов:\n";
    for (const auto& s : students) {
        wcout
            << L"-------------------------\n"
            << L"ФИО: " << s.academics.lastName << L" "
            << s.academics.firstName << L" "
            << s.academics.patronymic << L"\n"
            << L"Курс: " << s.academics.course << L"\n"
            << L"Пол: " << s.personal.gender << L"\n"
            << L"Год рождения: " << s.personal.birthYear << L"\n"
            << L"Оценки:\n"
            << L"  Физика: " << s.academics.physics << L"\n"
            << L"  Математика: " << s.academics.math << L"\n"
            << L"  Программирование: " << s.academics.programming << L"\n";
    }
    
    
    


    wcout << L"--- До сортировки ---" << endl;
    for (const auto& s : students) {
        printStudent(s);
    }



    // --- Сортировка с помощью лямбда-функции ---

    sort(students.begin(), students.end(), [](const StudentFull& a, const StudentFull& b) {
        // Сравниваем фамилии
        if (a.academics.lastName != b.academics.lastName) {
            return a.academics.lastName < b.academics.lastName;
        }
        
        if (a.academics.firstName != b.academics.firstName) {
            return a.academics.firstName < b.academics.firstName;
        }
        
        return a.academics.patronymic < b.academics.patronymic;
        });






    wcout << L"\n--- После сортировки (по ФИО) ---" << endl;
    for (const auto& s : students) {
        printStudent(s);
    }


    int sum_phy = 0, sum_math = 0, sum_prog = 0;
    int n = 0;
    for (const auto& s : students) { 
        sum_phy += s.academics.physics;
        sum_math += s.academics.math;
        sum_prog += s.academics.programming;

        n++;
    }

    double m = min(min(sum_phy, sum_math), sum_prog);
    cout << '\n' << endl << endl << endl;
    if (m == sum_phy) {
        wcout << L"Наихудший средний балл по физике: " << m / n;
    }
    else if (m == sum_math) {
        wcout << L"Наихудший средний балл по математике: " << m / n;
    }
    else {
        wcout << L"Наихудший средний балл по программированию: " << m / n;
    }

    wcout << '\n' << endl << endl << endl;











    return 0;
}













//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <string>
//using namespace std;
//struct StudentAcademics {
//    std::string lastName;
//    std::string firstName;
//    std::string patronymic;
//    int course;
//    int physics;
//    int math;
//    int programming;
//};
//
//struct StudentPersonal {
//    std::string lastName;
//    std::string firstName;
//    std::string patronymic;
//    char gender;
//    int birthYear;
//};
//
//struct StudentFull {
//    StudentAcademics academics;
//    StudentPersonal personal;
//};
//
//std::vector<StudentAcademics> readScores(const std::string& filename) {
//    std::vector<StudentAcademics> students;
//    std::ifstream file(filename);
//
//    if (!file.is_open()) {
//        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
//        return students;
//    }
//
//    std::string line;
//    while (std::getline(file, line)) {
//        std::stringstream ss(line);
//        StudentAcademics s;
//        std::string token;
//
//        if (!std::getline(ss, s.lastName, ',')) break;
//        if (!std::getline(ss, s.firstName, ',')) break;
//        if (!std::getline(ss, s.patronymic, ',')) break;
//        if (!std::getline(ss, token, ',')) break; s.course = std::stoi(token);
//        if (!std::getline(ss, token, ',')) break; s.physics = std::stoi(token);
//        if (!std::getline(ss, token, ',')) break; s.math = std::stoi(token);
//        if (!std::getline(ss, token, ',')) break; s.programming = std::stoi(token);
//
//        students.push_back(s);
//    }
//
//    return students;
//}
//
//std::vector<StudentPersonal> readPersonal(const std::string& filename) {
//    std::vector<StudentPersonal> students;
//    std::ifstream file(filename);
//
//    if (!file.is_open()) {
//        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
//        return students;
//    }
//
//    std::string line;
//    while (std::getline(file, line)) {
//        std::stringstream ss(line);
//        StudentPersonal s;
//        std::string token;
//
//        if (!std::getline(ss, s.lastName, ',')) break;
//        if (!std::getline(ss, s.firstName, ',')) break;
//        if (!std::getline(ss, s.patronymic, ',')) break;
//        if (!std::getline(ss, token, ',')) break; s.gender = token.empty() ? ' ' : token[0];
//        if (!std::getline(ss, token, ',')) break; s.birthYear = token.empty() ? 0 : std::stoi(token);
//
//        students.push_back(s);
//    }
//
//    return students;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    //SetConsoleOutputCP(1251);
//    //SetConsoleCP(1251);
//    SetConsoleCP(CP_UTF8);     // Входная кодовая страница
//    SetConsoleOutputCP(CP_UTF8); // Выходная кодовая страница
//
//    system("chcp 65001 > nul"); // Скрываем вывод команды
//    
//    // Чтение данных из файлов
//    auto academics = readScores("C:/Users/bardr/source/repos/Programming workshop/Лабы_по_cpp/лаб10/scores.csv");
//    auto personal = readPersonal("C:/Users/bardr/source/repos/Programming workshop/Лабы_по_cpp/лаб10/students.csv");
//
//    // Проверка успешности чтения
//    if (academics.empty() || personal.empty()) {
//        std::cerr << "Ошибка: один из файлов пуст или не был прочитан!" << std::endl;
//        return 1;
//    }
//
//    // Проверка количества записей
//    if (academics.size() != personal.size()) {
//        std::cerr << "Предупреждение: количество записей в файлах не совпадает!" << std::endl;
//    }
//
//    // Вывод данных для отладки
//    std::cout << "Прочитано из scores.csv: " << academics.size() << " записей" << std::endl;
//    std::cout << "Прочитано из students.csv: " << personal.size() << " записей" << std::endl;
//
//    // Объединение данных
//    std::vector<StudentFull> students;
//    size_t minSize = std::min(academics.size(), personal.size());
//
//    for (size_t i = 0; i < minSize; ++i) {
//        students.push_back({ academics[i], personal[i] });
//    }
//
//    // Вывод информации
//    std::cout << "\nСписок студентов:\n";
//    for (const auto& s : students) {
//        std::cout << "-------------------------\n";
//        std::cout << "ФИО: "
//            << s.academics.lastName << " "
//            << s.academics.firstName << " "
//            << s.academics.patronymic << "\n";
//
//        std::cout << "Курс: " << s.academics.course << "\n";
//        std::cout << "Пол: " << s.personal.gender << "\n";
//        std::cout << "Год рождения: " << s.personal.birthYear << "\n";
//        std::cout << "Оценки:\n";
//        std::cout << "  Физика: " << s.academics.physics << "\n";
//        std::cout << "  Математика: " << s.academics.math << "\n";
//        std::cout << "  Программирование: " << s.academics.programming << "\n";
//    }
//
//    return 0;
//}


//Информация о студентах размещается в двух двоичных файлах.В первом
//файле : фамилия, имя, отчество, курс, оценки по физике, математике, про -
//граммированию.Во втором файле для тех же студентов в том же порядке :
//фамилия, имя, отчество, пол, год рождения.Отсортировать фамилии в
//обоих файлах по алфавиту.Определить, по какому предмету больше всего
//не успевают юноши.


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
