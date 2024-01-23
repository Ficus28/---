#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class FileProcessor {
public:
    explicit FileProcessor(const std::string& filename) : filename(filename) {}

    void writeNumbersToFile(int count) {
        std::ofstream fileStream(filename);

        if (!fileStream.is_open()) {
            std::cerr << "Не удается открыть файл для записи: " << filename << std::endl;
            return;
        }

        for (int i = 1; i <= count; ++i) {
            fileStream << i << std::endl;
        }

        fileStream.close();
        std::cout << "Числа успешно записаны в файл." << std::endl;
    }

    void writeNumbersToFileFromConsole() {
        std::ofstream fileStream(filename);

        if (!fileStream.is_open()) {
            std::cerr << "Не удается открыть файл для записи: " << filename << std::endl;
            return;
        }

        int count;
        std::cout << "Введите количество чисел для записи в файл: ";
        std::cin >> count;

        for (int i = 1; i <= count; ++i) {
            int number;
            std::cout << "Введите число " << i << ": ";
            std::cin >> number;
            fileStream << number << std::endl;
        }

        fileStream.close();
        std::cout << "Числа успешно записаны в файл." << std::endl;
    }

    bool readAndPrintLinesWithTwoDigitNumbers() {
        std::ifstream fileStream(filename);

        if (!fileStream.is_open()) {
            std::cerr << "Не удается открыть файл для чтения: " << filename << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(fileStream, line)) {
            if (containsTwoDigitNumber(line)) {
                std::cout << line << std::endl;
            }
        }

        fileStream.close();
        return true;
    }

private:
    bool containsTwoDigitNumber(const std::string& line) const {
        for (size_t i = 0; i < line.length(); ++i) {
            if (isdigit(line[i])) {
                // Если найдена цифра, проверяем следующий символ
                if (i + 1 < line.length() && isdigit(line[i + 1])) {
                    // Если следующий символ - тоже цифра, это двузначное число
                    return true;
                }
            }
        }
        return false;
    }

    std::string filename;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string filename;

    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    FileProcessor fileProcessor(filename);

    // Записываем числа в файл
    // fileProcessor.writeNumbersToFile(20);

    // Записываем числа в файл через ввод с клавиатуры
    fileProcessor.writeNumbersToFileFromConsole();

    // Считываем и выводим строки с двузначными числами
    if (fileProcessor.readAndPrintLinesWithTwoDigitNumbers()) {
        std::cout << "Строки с двузначными числами выведены успешно." << std::endl;
    }
    else {
        std::cout << "Произошла ошибка при чтении файла." << std::endl;
    }

    return 0;
}
