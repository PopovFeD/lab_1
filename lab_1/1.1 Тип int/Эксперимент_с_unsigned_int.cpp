#include <iostream>
#include <bitset>

#include <windows.h>

void printBits(unsigned int n)
{
    std::cout << "Число: " << n << std::endl;
    std::cout << "Побитовое представление: " << std::bitset<sizeof(unsigned int) * 8>(n) << std::endl;
}

int main()
{
    SetConsoleOutputCP(65001); // Устанавливаем кодировку UTF-8 для вывода
    SetConsoleCP(65001);       // Устанавливаем кодировку UTF-8 для ввода

    unsigned int zero = 0;

    std::cout << "Начальное значение (0):" << std::endl;
    printBits(zero);

    std::cout << "\nПосле вычитания 1:" << std::endl;
    printBits(zero - 1);

    return 0;
}
