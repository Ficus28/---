from Complex import Complex

def main():
    # Создаем объекты
    c1 = Complex(2, 3)
    c2 = Complex(1, 2)

    # Тестируем базовые операции
    print("c1 =", c1)
    print("c2 =", c2)

    print("c1 + c2 =", c1 + c2)
    print("c1 - c2 =", c1 - c2)
    print("c1 * c2 =", c1 * c2)
    print("c1 / c2 =", c1 / c2)

    # Тестируем метод from_string
    c3 = Complex.from_string("5.5+2.5j")
    print("c3 =", c3)

    # Тестируем методы save и load
    c1.save("complex_data.json")
    c4 = Complex.load("complex_data.json")
    print("c4 (loaded from file) =", c4)

    # Тестируем дополнительные методы и свойства
    print("Real part of c1:", c1.get_real())
    print("Imaginary part of c1:", c1.get_imaginary())

    c1.set_real(10)
    c1.set_imaginary(20)
    print("Updated c1 =", c1)

if __name__ == "__main__":
    main()