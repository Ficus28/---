#include "BinString.h"
#include <iostream>
#include <bitset>

void BinString::Create1() {
    std::cout << "Введите первое значение типа BinString" << std::endl;
    std::cin >> c;

    std::cout << "Первое значение типа BinString = " << c << std::endl;
    if (!IsBinaryString(c)) {
        std::cerr << "Ошибка: Введено не двоичное число. Повторите ввод." << std::endl;
        Create1();
        return;
    }
}

void BinString::Create2() {
    std::cout << "Введите второе значение типа BinString" << std::endl;
    std::cin >> d;

    std::cout << "Второе значение типа BinString = " << d << std::endl;

    if (!IsBinaryString(d)) {
        std::cerr << "Ошибка: Введено не двоичное число. Повторите ввод." << std::endl;
        Create1();
        return;
    }
}

bool BinString::IsBinaryString(const std::string& str) {
    for (char digit : str) {
        if (digit != '0' && digit != '1') {
            return false;
        }
    }
    return true;
}

void BinString::Init() {
    try {
        // Вычитаем
        int result = std::stoi(c, nullptr, 2) - std::stoi(d, nullptr, 2);
        std::cout << "BinString: " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}
