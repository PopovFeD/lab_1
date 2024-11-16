#include <iostream>
#include <climits>
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

    std::cout << "INT_MAX:" << std::endl;
    printBits(INT_MAX);

    std::cout << "\nINT_MAX + 1 (переполнение):" << std::endl;
    printBits(INT_MAX + 1);

    return 0;
}
