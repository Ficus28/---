#include <windows.h>
#include <chrono>
#include "Type.h"       
#include "SymbString.h"
#include "BinString.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
using namespace chrono;

class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        setvbuf(stderr, NULL, _IONBF, 0);
        auto finish = steady_clock::now();
        auto dur = finish - start;
        std::cerr << "Время выполнения программы: " << duration_cast<seconds>(dur).count()
            << " секунд" << std::endl;
    }

private:
    steady_clock::time_point start;
};

void printHelp() {
    cout << "Для ввода данных нажмите 1\n";
    cout << "Для вычитания нажмите 2\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    {
        LogDuration programDuration;

        int choice = 0;
        bool exitProgram = false;

        Type* symbString = new SymbString();
        Type* binString = new BinString();

        while (!exitProgram) {
            printHelp();

            cin.sync();

            cin >> choice;

            switch (choice) {
            case 1:
                symbString->Create1();
                symbString->Create2();
                binString->Create1();
                binString->Create2();
                break;

            case 2:
                symbString->Init();
                binString->Init();
                break;

            default:
                cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
            }
        }

        delete symbString;
        delete binString;

        return 0;
    }
}
