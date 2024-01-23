#include "BinString.h"
#include <iostream>
#include <bitset>

void BinString::Create1() {
    std::cout << "������� ������ �������� ���� BinString" << std::endl;
    std::cin >> c;

    std::cout << "������ �������� ���� BinString = " << c << std::endl;
    if (!IsBinaryString(c)) {
        std::cerr << "������: ������� �� �������� �����. ��������� ����." << std::endl;
        Create1();
        return;
    }
}

void BinString::Create2() {
    std::cout << "������� ������ �������� ���� BinString" << std::endl;
    std::cin >> d;

    std::cout << "������ �������� ���� BinString = " << d << std::endl;

    if (!IsBinaryString(d)) {
        std::cerr << "������: ������� �� �������� �����. ��������� ����." << std::endl;
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
        // ��������
        int result = std::stoi(c, nullptr, 2) - std::stoi(d, nullptr, 2);
        std::cout << "BinString: " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }
}
