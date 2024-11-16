#include <iostream>
#include <bitset>

#include <windows.h>

void printBits(int n)
{
    std::cout << "Число: " << n << std::endl;
    std::cout << "Побитовое представление: " << std::bitset<sizeof(int) * 8>(n) << std::endl;
}

int main()
{
    SetConsoleOutputCP(65001); // Устанавливаем кодировку UTF-8 для вывода
    SetConsoleCP(65001);       // Устанавливаем кодировку UTF-8 для ввода

    int num1 = 42;
    int num2 = -42;

    std::cout << "Пример 1:" << std::endl;
    printBits(num1);

    std::cout << "\nПример 2 (отрицательное число):" << std::endl;
    printBits(num2);

    return 0;
}
