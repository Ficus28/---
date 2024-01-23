#include "SymbString.h"
#include <iostream>

void SymbString::Create1() {
    std::cout << "Введите первое значение типа SymbString" << std::endl;
    std::cin >> a;
    std::cout << "Первое значение типа SymbString = " << a << std::endl;
}

void SymbString::Create2() {
    std::cout << "Введите второе значение типа SymbString" << std::endl;
    std::cin >> b;
    std::cout << "Второе значение типа SymbString = " << b << std::endl;
}

void SymbString::Init() {
    size_t pos = a.find(b);
    if (pos != std::string::npos) {
        a.erase(pos, b.length());
    }
    std::cout << "SymbString: " << a << std::endl;
}
