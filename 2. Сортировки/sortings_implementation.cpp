#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <random>

#include <windows.h>

// Функция для генерации случайного массива, который будем сортировать
int* generateRandomArray(int length, unsigned int seed, int min = 0, int max = 100)
{
    if (length < 0)
    {
        throw std::invalid_argument("Негативная длина массива");
    }

    int* array = new (std::nothrow) int[length];
    if (!array)
    {
        throw std::bad_alloc();
    }

    try
    {
        // Инициализация генератора Mersenne Twister с переданным зерном
        std::mt19937 gen(seed);

        std::uniform_int_distribution<> dist(min, max);

        for (int i = 0; i < length; ++i)
        {
            array[i] = dist(gen);
        }
    }
    catch (const std::exception& ex)
    {
        delete[] array;
        throw;
    }

    return array;
}

// Вспомогательная функция для просеивания элемента вниз в куче
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Сортировка кучей
void heapSort(int *arr, int n)
{
    // Построение максимальной кучи
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлечение элементов из кучи по одному
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Вспомогательная функция для слияния двух отсортированных подмассивов
void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Рекурсивная функция сортировки слиянием
void mergeSortRecursive(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Вспомогательная функция для вывода массива
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Пример использования
int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001); // Устанавливаем кодировку UTF-8 для вывода
    SetConsoleCP(65001);       // Устанавливаем кодировку UTF-8 для ввода

     // Проверяем, переданы ли два аргумента
    if (argc != 4) {
        std::cerr << "Использование: program.exe <число> <сид> <строка>" << std::endl;
        return 1; // Завершаем с ошибкой
    }

    try {
        // Парсим число
        int number = std::stoi(argv[1]); // Преобразуем первый аргумент в число

        // Парсим сид
        int seed = std::stoi(argv[2]); // Преобразуем первый аргумент в число

        // Получаем строку
        std::string text = argv[3];

        // std::cout << "Число: " << number << std::endl;
        // std::cout << "Строка: " << text << std::endl;

        auto arr = generateRandomArray(number, seed);

        // printArray(arr, number);

        auto start = std::chrono::high_resolution_clock::now();

        // Выполняем сортировку в зависимости от строки
        if (text == "heap") {
            heapSort(arr, number);
        }
        else if (text == "merge") {
            mergeSortRecursive(arr, 0, number - 1);
        }
        else {
            throw std::invalid_argument("Неверная строка");
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        // printArray(arr, number);

        // std::cout << "Время сортировки: " << duration.count() << " секунд" << std::endl;
        std::cout << duration.count();

        return 0;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка при парсинге аргументов: "<< e.what() << std::endl;
        return 1;
    }
}
