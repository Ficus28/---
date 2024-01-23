#include <iostream>
#include <cmath>

// Базовый класс для геометрических фигур
class Shape {
public:
    virtual void draw() const = 0;
    virtual void move(double deltaX, double deltaY) = 0;
    virtual void resize(double factor) = 0;
    virtual void rotate(double angle) = 0;
    virtual ~Shape() {}
};

// Класс для круга
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        std::cout << "Circle with radius " << radius << std::endl;
    }

    void move(double deltaX, double deltaY) override {
        // Реализация перемещения круга
        // (здесь просто вывод сообщения для демонстрации)
        std::cout << "Circle moved by (" << deltaX << ", " << deltaY << ")" << std::endl;
    }

    void resize(double factor) override {
        radius *= factor;
        std::cout << "Circle resized by factor " << factor << std::endl;
    }

    void rotate(double angle) override {
        // Реализация вращения круга
        // (здесь просто вывод сообщения для демонстрации)
        std::cout << "Circle rotated by angle " << angle << " degrees" << std::endl;
    }
};

// Класс для квадрата
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    void draw() const override {
        std::cout << "Square with side " << side << std::endl;
    }

    void move(double deltaX, double deltaY) override {
        std::cout << "Square moved by (" << deltaX << ", " << deltaY << ")" << std::endl;
    }

    void resize(double factor) override {
        side *= factor;
        std::cout << "Square resized by factor " << factor << std::endl;
    }

    void rotate(double angle) override {
        std::cout << "Square rotated by angle " << angle << " degrees" << std::endl;
    }
};

// Класс для прямоугольника
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        std::cout << "Rectangle with width " << width << " and height " << height << std::endl;
    }

    void move(double deltaX, double deltaY) override {
        std::cout << "Rectangle moved by (" << deltaX << ", " << deltaY << ")" << std::endl;
    }

    void resize(double factor) override {
        width *= factor;
        height *= factor;
        std::cout << "Rectangle resized by factor " << factor << std::endl;
    }

    void rotate(double angle) override {
        std::cout << "Rectangle rotated by angle " << angle << " degrees" << std::endl;
    }
};

// Функция для демонстрации работы с фигурами
void demonstrateShapes(Shape* shape) {
    shape->draw();
    shape->move(2.0, 3.0);
    shape->resize(1.5);
    shape->rotate(45.0);
}

int main() {
    // Пример использования для каждой фигуры
    Circle circle(5.0);
    Square square(4.0);
    Rectangle rectangle(6.0, 8.0);

    std::cout << "Demonstrating Circle:" << std::endl;
    demonstrateShapes(&circle);

    std::cout << "\nDemonstrating Square:" << std::endl;
    demonstrateShapes(&square);

    std::cout << "\nDemonstrating Rectangle:" << std::endl;
    demonstrateShapes(&rectangle);

    return 0;
}
