#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include <Windows.h>

class File {
public:
    File(const std::string& name) : name(name), creationDate(time(nullptr)), accessCount(0) {}

    const std::string& getName() const {
        return name;
    }

    std::string getCreationDate() const {
        char buffer[26];
        // Используем безопасную функцию ctime_s
        ctime_s(buffer, sizeof(buffer), &creationDate);
        // Убираем символ новой строки, который добавляется функцией ctime
        buffer[24] = '\0';
        return buffer;
    }

    int getAccessCount() const {
        return accessCount;
    }

    void incrementAccessCount() {
        accessCount++;
    }

private:
    std::string name;
    time_t creationDate;
    int accessCount;
};

class FileManager {
public:
    void addFile(const std::string& name) {
        files.push_back(File(name));
    }

    void printCatalog() const {
        std::cout << "Каталог:\n";
        for (const auto& file : files) {
            std::cout << "Имя: " << file.getName()
                << ", Дата создания: " << file.getCreationDate()
                << ", Количество обращений: " << file.getAccessCount() << std::endl;
        }
    }

    void deleteFilesOlderThan(time_t date) {
        files.remove_if([date](const File& file) {
            // Используем безопасную функцию ctime_s
            char buffer[26];
            ctime_s(buffer, sizeof(buffer), &date);
            return file.getCreationDate() < buffer;
            });
    }

    File findFileWithMaxAccessCount() const {
        if (files.empty()) {
            throw std::runtime_error("Каталог пуст.");
        }

        auto maxAccessFile = std::max_element(files.begin(), files.end(),
            [](const File& a, const File& b) {
                return a.getAccessCount() < b.getAccessCount();
            });

        return *maxAccessFile;
    }

private:
    std::list<File> files;
};

int main() {
    // Устанавливаем кодировку для консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FileManager fileManager;

    // Начальное формирование каталога
    fileManager.addFile("file1");
    fileManager.addFile("file2");
    fileManager.addFile("file3");

    int choice;
    time_t deletionDate;

    do {
        // Вывод меню
        std::cout << "\nМеню:\n";
        std::cout << "1. Вывести каталог\n";
        std::cout << "2. Удалить файлы старше заданной даты\n";
        std::cout << "3. Найдите файл с Максимальным количеством обращений\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите свой выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Вывод каталога
            fileManager.printCatalog();
            break;

        case 2:
            // Удаление файлов старше заданной даты
            std::cout << "Введите дату удаления (временную метку Unix): ";
            std::cin >> deletionDate;
            fileManager.deleteFilesOlderThan(deletionDate);
            std::cout << "Файл удален.\n";
            break;

        case 3:
            // Поиск файла с наибольшим количеством обращений
            try {
                File maxAccessFile = fileManager.findFileWithMaxAccessCount();
                std::cout << "Файл с максимальным количеством обращений:\n";
                std::cout << "Имя: " << maxAccessFile.getName()
                    << ", Количество обращений: " << maxAccessFile.getAccessCount() << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }
            break;

        case 0:
            // Выход из программы
            std::cout << "Выходим...\n";
            break;

        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
