/*
Задание 2. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Заменить все элементы с четными 
значениями с номерами от n1 до n2 на максимальный по модулю элемент этого 
массива. n1, n2 вводятся с клавиатуры. Сделать проверку на корректность ввода 
n, n1 и n.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <random>

int main() 
{
    const int MAX_SIZE = 20;
    const int MIN_RANGE = -50;
    const int MAX_RANGE = 50;
    
    
    int SIZE;
    std::cout << "Введите размер массива(не больше 20): ";
    std::cin >> SIZE;

    // Проверка корректности ввода для n
    while (SIZE <= 0 || SIZE > MAX_SIZE || std::cin.fail()) 
    {
        std::cout << "\nРазмер массива должен быть в диапазоне от 1 до " << MAX_SIZE;
        std::cout << "\nВведите размер массива:";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> SIZE;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(MIN_RANGE, MAX_RANGE);
    
    int* array = new int[SIZE];

    // Заполнение массива случайными числами
    for (int i = 0; i < SIZE; ++i) 
    {
        array[i] = dis(gen); // генерируем случайное число из диапазона [-50, 50]
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; ++i) 
    {
        std::cout << array[i] << std::setw(4);
    }
    std::cout << std::endl;

    int n1, n2;
    do 
    {
        std::cout << "Введите значения n1 и n2 (от 1 до " << SIZE << "): ";
        std::cin >> n1 >> n2;
    
        // Проверка корректности ввода для n1 и n2
        if (n1 <= 0 || n1 > SIZE || n2 <= 0 || n2 > SIZE || n1 > n2) 
        {
            std::cout << "Некорректный ввод для n1 и/или n2." << std::endl;
        }
    } 
    while (n1 <= 0 || n1 > SIZE || n2 <= 0 || n2 > SIZE || n1 > n2);

    

    // Нахождение максимального по модулю элемента массива
    int max_abs = 0;
    for (int i = 0; i < SIZE; ++i) 
    {
        if (abs(array[i]) > abs(max_abs)) 
        {
            max_abs = array[i];
        }
    }

    // Замена элементов с четными значениями в указанном диапазоне на максимальный по модулю элемент
    for (int i = n1 - 1; i < n2 - 1; ++i) 
    {
        if (array[i] % 2 == 0) 
        {
            array[i] = max_abs;
        }
    }

    std::cout << "Модифицированный массив: ";
    for (int i = 0; i < SIZE; ++i) 
    {
        std::cout << array[i] << std::setw(4);
    }
    std::cout << std::endl;
    
    delete[] array;
    
    return 0;
}