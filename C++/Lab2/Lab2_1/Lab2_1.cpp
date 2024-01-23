#include <iostream>
#include <bitset>

class T1 {
public:
    std::string id;
    int value;

    T1(std::string id, int value) : id(id), value(value) {}

    void showValue() const {
        std::cout << "T1 Object: " << value << std::endl;
    }

    void showBin() const {
        std::cout << "Binary representation: ";
        std::cout << std::bitset<32>(value) << std::endl;
    }

    void showOct() const {
        std::cout << "Octal representation: ";
        std::cout << std::oct << value << std::dec << std::endl;
    }

    void showDec() const {
        std::cout << "Decimal representation: " << value << std::endl;
    }

    void showHex() const {
        std::cout << "Hexadecimal representation: 0x" << std::hex << value << std::dec << std::endl;
    }

    friend T1 operator+(const T1& s1, const T1& s2) {
        T1 result = s1;
        result.value += s2.value;
        return result;
    }

    friend T1 operator-(const T1& s1, const T1& s2) {
        T1 result = s1;
        result.value -= s2.value;
        return result;
    }

    void additionalOperation1() const {
        // Реализация дополнительной операции для T1
    }

    void additionalOperation2() const {
        // Реализация второй дополнительной операции для T1
    }
};

class T2 {
public:
    std::string id;
    int value;

    T2(std::string id, int value) : id(id), value(value) {}

    void showValue() const {
        std::cout << "T2 Object: " << value << std::endl;
    }

    void showBin() const {
        std::cout << "Binary representation: ";
        std::cout << std::bitset<32>(value) << std::endl;
    }

    void showOct() const {
        std::cout << "Octal representation: ";
        std::cout << std::oct << value << std::dec << std::endl;
    }

    void showDec() const {
        std::cout << "Decimal representation: " << value << std::endl;
    }

    void showHex() const {
        std::cout << "Hexadecimal representation: 0x" << std::hex << value << std::dec << std::endl;
    }

    friend T2 operator+(const T2& s1, const T2& s2) {
        T2 result = s1;
        result.value += s2.value;
        return result;
    }

    friend T2 operator-(const T2& s1, const T2& s2) {
        T2 result = s1;
        result.value -= s2.value;
        return result;
    }

    void additionalOperation3() const {
        // Реализация дополнительной операции для T2
    }

    void additionalOperation4() const {
        // Реализация второй дополнительной операции для T2
    }
};

class Factory {
public:
    static T1 createT1(std::string id, int value) {
        return T1(id, value);
    }

    static T2 createT2(std::string id, int value) {
        return T2(id, value);
    }

    static void showBin(const T1& obj) {
        obj.showBin();
    }

    static void showOct(const T1& obj) {
        obj.showOct();
    }

    static void showDec(const T1& obj) {
        obj.showDec();
    }

    static void showHex(const T1& obj) {
        obj.showHex();
    }

    static void showBin(const T2& obj) {
        obj.showBin();
    }

    static void showOct(const T2& obj) {
        obj.showOct();
    }

    static void showDec(const T2& obj) {
        obj.showDec();
    }

    static void showHex(const T2& obj) {
        obj.showHex();
    }

    static T1 operator+(const T1& s1, const T1& s2) {
        return s1 + s2;
    }

    static T1 operator-(const T1& s1, const T1& s2) {
        return s1 - s2;
    }

    static T2 operator+(const T2& s1, const T2& s2) {
        return s1 + s2;
    }

    static T2 operator-(const T2& s1, const T2& s2) {
        return s1 - s2;
    }
};

int main() {
    T1 t1Obj = Factory::createT1("ID1", 42);
    T2 t2Obj = Factory::createT2("ID2", 24);

    t1Obj.showValue();
    Factory::showBin(t1Obj);
    Factory::showOct(t1Obj);
    Factory::showDec(t1Obj);
    Factory::showHex(t1Obj);

    t2Obj.showValue();
    Factory::showBin(t2Obj);
    Factory::showOct(t2Obj);
    Factory::showDec(t2Obj);
    Factory::showHex(t2Obj);

    T1 result1 = Factory::operator+(t1Obj, t1Obj);
    result1.showValue();

    T2 result2 = Factory::operator-(t2Obj, t2Obj);
    result2.showValue();

    return 0;
}
