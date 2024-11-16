#include <iostream>
#include <iomanip>
#include <cmath>

#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001); // Устанавливаем кодировку UTF-8 для вывода
    SetConsoleCP(65001);       // Устанавливаем кодировку UTF-8 для ввода

    float a = 1.0f;

    while (true)
    {
        float b = std::nextafterf(a, INFINITY);
        if (b - a >= 1.0f)
        {
            std::cout << std::setprecision(20);
            std::cout << "Первое число a: " << a << std::endl;
            std::cout << "Второе число b: " << b << std::endl;
            std::cout << "Разница b - a: " << b - a << std::endl;
            break;
        }
        a = b;
    }

    // Проверка свойства x == x + 1 для всех x > a
    float x = a + 1.0f;
    std::cout << "\nПроверка x == x + 1 для x > a:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "x = " << x << ", x + 1 = " << x + 1 << ", равны: " << (x == x + 1) << std::endl;
        x = std::nextafterf(x, INFINITY);
    }

    return 0;
}
