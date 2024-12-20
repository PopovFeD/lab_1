#include <iostream>
#include <iomanip>

#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001); // Устанавливаем кодировку UTF-8 для вывода
    SetConsoleCP(65001);       // Устанавливаем кодировку UTF-8 для ввода

    float b = 0.2f;
    float c = 0.3f;

    std::cout << std::setprecision(20);
    std::cout << ((a + b) + c == a + (b + c)) << std::endl;

    return 0;
}
