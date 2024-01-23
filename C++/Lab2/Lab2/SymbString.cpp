#include "SymbString.h"
#include <iostream>

void SymbString::Create1() {
    std::cout << "������� ������ �������� ���� SymbString" << std::endl;
    std::cin >> a;
    std::cout << "������ �������� ���� SymbString = " << a << std::endl;
}

void SymbString::Create2() {
    std::cout << "������� ������ �������� ���� SymbString" << std::endl;
    std::cin >> b;
    std::cout << "������ �������� ���� SymbString = " << b << std::endl;
}

void SymbString::Init() {
    size_t pos = a.find(b);
    if (pos != std::string::npos) {
        a.erase(pos, b.length());
    }
    std::cout << "SymbString: " << a << std::endl;
}
