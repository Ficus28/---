# Задание №1.
#
# Выполнил: Кобылка Кирилл Константинович.
# Группа: ПИН-б-о-21-1
# E-mail: kivi3viki4@gmail.com



class Roman:

    ARABIC_MIN = 1
    ARABIC_MAX = 3999
    ROMAN_MIN = "I"
    ROMAN_MAX = "MMMCMXCIX"

    LETTERS = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    NUMBERS = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

    @property
    def arabic(self):
        return self._arabic

    def __init__(self, value):

        if not isinstance(value, (int, str)):
            raise TypeError("Не удается создать римское число из {0}".format(type(value)))

        if isinstance(value, int):
            self._arabic = value
        elif isinstance(value, str):
            self._arabic = self.to_arabic(value)

    def __add__(self, other):
        if isinstance(other, Roman):
            result_arabic = self._arabic + other._arabic
        elif isinstance(other, int):
            result_arabic = self._arabic + other
        else:
            raise TypeError("Не удается добавить римскую цифру к {0}".format(type(other)))

        if not self.ARABIC_MIN <= result_arabic <= self.ARABIC_MAX:
            raise ValueError("Результат слишком мал или слишком велик для римских цифр")

        return Roman(result_arabic)

    def __sub__(self, other):
        if isinstance(other, Roman):
            result_arabic = self._arabic - other._arabic
        elif isinstance(other, int):
            result_arabic = self._arabic - other
        else:
            raise TypeError("Невозможно вычесть {0} из римского числа".format(type(other)))

        if not self.ARABIC_MIN <= result_arabic <= self.ARABIC_MAX:
            raise ValueError("Результат слишком мал или слишком велик для римских цифр")

        return Roman(result_arabic)

    def __mul__(self, other):
        if isinstance(other, Roman):
            result_arabic = self._arabic * other._arabic
        elif isinstance(other, int):
            result_arabic = self._arabic * other
        else:
            raise TypeError("Невозможно умножить римское число на {0}".format(type(other)))

        if not self.ARABIC_MIN <= result_arabic <= self.ARABIC_MAX:
            raise ValueError("Результат слишком мал или слишком велик для римских цифр")

        return Roman(result_arabic)

    def __floordiv__(self, other):
        if isinstance(other, Roman):
            result_arabic = self._arabic // other._arabic
        elif isinstance(other, int):
            result_arabic = self._arabic // other
        else:
            raise TypeError("Не удается разделить римское число на {0}".format(type(other)))

        if not self.ARABIC_MIN <= result_arabic <= self.ARABIC_MAX:
            raise ValueError("Результат слишком мал или слишком велик для римских цифр")

        return Roman(result_arabic)

    def __truediv__(self, other):
        return self.__floordiv__(other)

    def __str__(self):
        return self.to_roman(self._arabic)

    @staticmethod
    def to_arabic(roman):
        arabic = 0
        prev_value = 0

        for letter in reversed(roman):
            value = Roman.__letter_to_number(letter)
            if value < prev_value:
                arabic -= value
            else:
                arabic += value
            prev_value = value

        if not Roman.ARABIC_MIN <= arabic <= Roman.ARABIC_MAX:
            raise ValueError("Арабский номер находится вне зоны действия сети")

        return arabic

    @staticmethod
    def to_roman(arabic):
        if not Roman.ARABIC_MIN <= arabic <= Roman.ARABIC_MAX:
            raise ValueError("Арабский номер находится вне зоны действия сети")

        roman = ""
        n = arabic

        for i, number in enumerate(Roman.NUMBERS):
            while n >= number:
                roman += Roman.LETTERS[i]
                n -= number

        return roman

    @staticmethod
    def __letter_to_number(letter):
        letter = letter.upper()
        return Roman.NUMBERS[Roman.LETTERS.index(letter)]
