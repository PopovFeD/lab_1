#include <iostream>
#include <iomanip>

#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001); // Устанавливаем кодировку UTF-8 для вывода
    SetConsoleCP(65001);       // Устанавливаем кодировку UTF-8 для ввода

    float a = 1e20f;
    float b = -1e20f;
    float c = 1.0f;

    float result1 = (a + b) + c;
    float result2 = a + (b + c);

    std::cout << std::setprecision(20);
    std::cout << "(a + b) + c = " << result1 << std::endl;
    std::cout << "a + (b + c) = " << result2 << std::endl;
    std::cout << "Равны: " << (result1 == result2) << std::endl;

    return 0;
}
