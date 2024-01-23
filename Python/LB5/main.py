from vector import Vector, VectorCollection

if __name__ == "__main__":

    # Пример использования:
    collection = VectorCollection()
    collection.add(Vector(1, 2))
    collection.add(Vector(3, 4))
    collection.add(Vector(5, 6))

    print("Первоначальный сбор:", collection)

    # Удаляем элемент по индексу 1
    collection.remove(1)
    print("После удаления с индексом 1:", collection)

    # Сохраняем в файл
    collection.save("vector_collection.json")

    # Создаем новый объект и загружаем из файла
    new_collection = VectorCollection()
    new_collection.load("vector_collection.json")
    print("Загруженная коллекция:", new_collection)
