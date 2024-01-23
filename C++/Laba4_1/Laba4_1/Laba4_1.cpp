#include <iostream>
#include <algorithm>
#include <sstream>
#include <windows.h>

const int max_students = 10; // Максимальное количество студентов

class Student {
public:
    // Конструктор по умолчанию
    Student() : full_name(""), group_number("") {
        std::fill(grades, grades + max_students, 0); // Инициализация массива оценок нулями
    }

    Student(const std::string& full_name, const std::string& group_number, const int grades[max_students])
        : full_name(full_name), group_number(group_number) {
        std::copy(grades, grades + max_students, this->grades);
    }

    std::string get_full_name() const {
        return full_name;
    }

    std::string get_group_number() const {
        return group_number;
    }

    const int* get_grades() const {
        return grades;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << student.full_name << ", Группа: " << student.group_number << ", Grades: ";
        for (int i = 0; i < max_students; ++i) {
            os << student.grades[i] << " ";
        }
        return os;
    }

private:
    std::string full_name;
    std::string group_number;
    int grades[max_students];
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student students[max_students] = {}; // Инициализация массива студентов

    // Ввод данных о студентах
    int num_students;
    std::cout << "Введите количество студентов: ";
    std::cin >> num_students;

    std::cin.ignore(); // очистим буфер ввода от символа новой строки

    for (int i = 0; i < num_students; ++i) {
        std::string full_name, group_number;

        std::cout << "Введите фамилию и инициалы студента: ";
        std::getline(std::cin, full_name);

        std::cout << "Введите группу студента: ";
        std::getline(std::cin, group_number);

        int grades[max_students]; // Используем массив вместо вектора

        std::cout << "Введите оценки студента через пробел: ";
        std::string grades_input;
        std::getline(std::cin, grades_input);

        std::istringstream iss(grades_input);
        int grade;
        int grade_index = 0;

        while (iss >> grade && grade_index < max_students) {
            grades[grade_index++] = grade;
        }

        // Используем конструктор Student для инициализации объекта
        students[i] = Student(full_name, group_number, grades);
    }

    // Сортировка студентов по фамилии
    std::sort(students, students + num_students, [](const Student& a, const Student& b) {
        return a.get_full_name() < b.get_full_name();
        });

    // Вывод информации о студентах с хотя бы одной оценкой 2
    bool found_students = false;
    for (int i = 0; i < num_students; ++i) {
        if (std::any_of(students[i].get_grades(), students[i].get_grades() + max_students, [](int grade) {
            return grade == 2;
            })) {
            std::cout << students[i] << std::endl;
            found_students = true;
        }
    }

    if (!found_students) {
        std::cout << "Нет студентов с оценкой 2." << std::endl;
    }

    return 0;
}
