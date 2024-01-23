#include <iostream>
#include <stdexcept>
#include <windows.h> // Добавлен заголовочный файл windows.h для использования SetConsoleCP и SetConsoleOutputCP

// Определение серверного класса B (динамический массив)
template <typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t size;

public:
    DynamicArray(size_t initialCapacity = 10) : capacity(initialCapacity), size(0) {
        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push(const T& value) {
        if (size == capacity) {
            // Увеличение размера массива при необходимости
            capacity *= 2;
            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    T pop() {
        if (size == 0) {
            throw std::out_of_range("Попытка извлечения из пустого массива");
        }
        return data[--size];
    }

    size_t getSize() const {
        return size;
    }
};

// Определение целевого шаблонного класса A (Stack)
template <typename T, class B = DynamicArray<T>>
class Stack {
private:
    B storage;

public:
    void push(const T& value) {
        storage.push(value);
    }

    T pop() {
        return storage.pop();
    }

    size_t getSize() const {
        return storage.getSize();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        // Использование шаблона для типов int, double, std::string
        Stack<int> intStack;
        intStack.push(42);
        std::cout << "Размер стека для int: " << intStack.getSize() << std::endl;
        std::cout << "Извлеченное значение: " << intStack.pop() << std::endl;

        Stack<double> doubleStack;
        doubleStack.push(3.14);
        std::cout << "Размер стека для double: " << doubleStack.getSize() << std::endl;
        std::cout << "Извлеченное значение: " << doubleStack.pop() << std::endl;

        Stack<std::string> stringStack;
        stringStack.push("Привет");
        std::cout << "Размер стека для string: " << stringStack.getSize() << std::endl;
        std::cout << "Извлеченное значение: " << stringStack.pop() << std::endl;

        // Попытка извлечения из пустого стека (приводит к исключению)
        // intStack.pop();
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
