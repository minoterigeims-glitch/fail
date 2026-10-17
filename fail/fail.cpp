
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

struct MyStruct
{
    string surname;
    string name;
    int age;
    string position;
    double salary;
};

vector<MyStruct> employees;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    ifstream file("text.txt");

    if (file.is_open()) {
        string line;

        
        while (getline(file, line)) {
            
            cout << line << endl;
        }

        file.close();
    }
    else {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
    }

        
    int choice;

    do
    {
        cout << "----------------------------------------- МЕНЮ -----------------------------------------" << endl;
        cout << "1 - Ввести дані співробітника" << endl;
        cout << "2 - Редагування даних співробітника" << endl;
        cout << "3 - Видалення співробітника" << endl;
        cout << "4 - Пошук співробітника за прізвищем" << endl;
        cout << "5 - Виведення інформації про всіх співробітників зазначеного віку" << endl;
        cout << "6 - Зберегти список у файл" << endl;
        cout << "0 - Вихід" << endl;

        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            MyStruct employee;

            cout << "Введіть прізвище: ";
            cin >> employee.surname;

            cout << "Введіть ім'я: ";
            cin >> employee.name;

            cout << "Введіть вік: ";
            cin >> employee.age;

            cout << "Введіть посаду: ";
            cin >> employee.position;

            cout << "Введіть зарплату: ";
            cin >> employee.salary;

            employees.push_back(employee);

            cout << "Співробітника додано!" << endl;

            break;
        }

        case 2:
        {
            bool found = false;
            cout << "Редагування співробітника." << endl;
            string searchSurname;
            cout << "Введіть прізвище співробітника: ";
            cin >> searchSurname;
            for (int i = 0; i < employees.size(); i++)
            {
                
                if (searchSurname == employees[i].surname) {
                    found = true;
                    cout << "Прізвище: " << employees[i].surname << endl;
                    cout << "Ім'я: " << employees[i].name << endl;
                    cout << "Вік: " << employees[i].age << endl;
                    cout << "Посада: " << employees[i].position << endl;
                    cout << "Зарплата: " << employees[i].salary << endl;

                    cout << "Введіть новепрізвище: ";
                    cin >> employees[i].surname;
                    cout << "Введіть нове ім'я: ";
                    cin >> employees[i].name;
                    cout << "Введіть новий вік: ";
                    cin >> employees[i].age;
                    cout << "Введіть нову посаду: ";
                    cin >> employees[i].position;
                    cout << "Введіть нову зарплату: ";
                    cin >> employees[i].salary;

                }
            }
               
            if (found == false)
                {
                    cout << "Співробітника з таким прізвищем не знайдено!" << endl;

                }
             

            
            break;
        }

        case 3:
        {
            bool found = false;
            cout << "Видалити співробітника." << endl;
            string searchSurname;
            cout << "Введіть прізвище співробітника: ";
            cin >> searchSurname;
            for (int i = 0; i < employees.size(); i++) {
                
                if (searchSurname == employees[i].surname) {
                    found = true;
                    cout << "Прізвище: " << employees[i].surname << endl;
                    cout << "Ім'я: " << employees[i].name << endl;
                    cout << "Вік: " << employees[i].age << endl;
                    cout << "Посада: " << employees[i].position << endl;
                    cout << "Зарплата: " << employees[i].salary << endl;

                    employees.erase(employees.begin() + i);
					cout << "Співробітника видалено!" << endl; 
                    break;
                }

            }
            if (found == false)
            {
                cout << "Співробітника з таким прізвищем не знайдено!" << endl;

            }
            break;
        }

        case 4:
        {
            cout << "Пошук співробітника за прізвищем" << endl;

            string searchSurname;
            cout << "Введіть прізвище співробітника: ";
            cin >> searchSurname;

            ofstream file("searchSurname.txt");
            bool found = false;

            if (!file.is_open())
            {
                cout << "Помилка відкриття файлу!" << endl;
                break;
            }

            for (int i = 0; i < employees.size(); i++)
            {
                if (searchSurname == employees[i].surname)
                {
                    found = true;

                    cout << "Прізвище: " << employees[i].surname << endl;
                    cout << "Ім'я: " << employees[i].name << endl;
                    cout << "Вік: " << employees[i].age << endl;
                    cout << "Посада: " << employees[i].position << endl;
                    cout << "Зарплата: " << employees[i].salary << endl;
                    cout << "--------------------------------" << endl;

                    file << "Прізвище: " << employees[i].surname << endl;
                    file << "Ім'я: " << employees[i].name << endl;
                    file << "Вік: " << employees[i].age << endl;
                    file << "Посада: " << employees[i].position << endl;
                    file << "Зарплата: " << employees[i].salary << endl;
                    file << "--------------------------------" << endl;
                }
            }

            file.close();

            if (found == false)
                cout << "Співробітника не знайдено!" << endl;
            else
                cout << "Результат збережено у searchSurname.txt" << endl;

            break;
        }
        

        case 5:
        {
            cout << "Пошук співробітника за віком" << endl;

            int searchAge;
            cout << "Введіть вік співробітника: ";
            cin >> searchAge;

            ofstream file("searchAge.txt");
            bool found = false;

            if (!file.is_open())
            {
                cout << "Помилка відкриття файлу!" << endl;
                break;
            }

            for (int i = 0; i < employees.size(); i++)
            {
                if (searchAge == employees[i].age)
                {
                    found = true;

                    cout << "Прізвище: " << employees[i].surname << endl;
                    cout << "Ім'я: " << employees[i].name << endl;
                    cout << "Вік: " << employees[i].age << endl;
                    cout << "Посада: " << employees[i].position << endl;
                    cout << "Зарплата: " << employees[i].salary << endl;
                    cout << "--------------------------------" << endl;

                    file << "Прізвище: " << employees[i].surname << endl;
                    file << "Ім'я: " << employees[i].name << endl;
                    file << "Вік: " << employees[i].age << endl;
                    file << "Посада: " << employees[i].position << endl;
                    file << "Зарплата: " << employees[i].salary << endl;
                    file << "--------------------------------" << endl;
                }
            }

            file.close();

            if (found == false)
                cout << "Співробітника не знайдено!" << endl;
            else
                cout << "Результат збережено у searchAge.txt" << endl;

            break;
        }
        

        case 6:
        {
            cout << "Кількість співробітників: "
                << employees.size() << endl;

            ofstream file("text.txt");

            if (!file.is_open())
            {
                cout << "Помилка відкриття файлу!" << endl;
                break;
            }

            for (int i = 0; i < employees.size(); i++)
            {
                file << "Прізвище: " << employees[i].surname << endl;
                file << "Ім'я: " << employees[i].name << endl;
                file << "Вік: " << employees[i].age << endl;
                file << "Посада: " << employees[i].position << endl;
                file << "Зарплата: " << employees[i].salary << endl;
                file << "--------------------------------" << endl;
            
            }

            file.close();

            cout << "Запис у файл завершено!" << endl;

            break;
        }

        case 0:
        {
            cout << "Завершення програми." << endl;
            break;
        }

        default:
        {
            cout << "Неправильний вибір!" << endl;
            break;
        }

        }

    } while (choice != 0);

    return 0;
}
