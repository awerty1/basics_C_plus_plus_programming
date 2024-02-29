/*
Задание 2. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Определить максимальное количество 
следующих подряд двоек. В массиве могут отсутствовать двойки, и такой 
вариант должен отрабатываться корректно. Сделать проверку на корректность 
ввода n.
*/

#include <iostream>
#include <cstdlib>
#include <ctime> // Для работы с функцией time()

int main() 
{
    int n;

    std::cout << "Введите количество элементов массива (не больше 20): ";
    std::cin >> n;

    if (n <= 0 || n > 20) 
    {
        std::cout << "Ошибка: введено некорректное значение n\n";
        return 1;
    }

    int A[n];

    // Заполнение массива случайными числами от 0 до 2
    srand(time(0));
    for (int i = 0; i < n; ++i) 
    {
        A[i] = rand() % 3; // Возможные значения: 0, 1, 2
    }

    int maxConsecutiveTwos = 0;
    int currentConsecutiveTwos = 0;

    // Поиск максимального количества последовательных двоек
    for (int i = 0; i < n; ++i) 
    {
        if (A[i] == 2) 
        {
            currentConsecutiveTwos++;
        } 
        else 
        {
            if (currentConsecutiveTwos > maxConsecutiveTwos) 
            {
                maxConsecutiveTwos = currentConsecutiveTwos;
            }
            currentConsecutiveTwos = 0;
        }
    }

    if (currentConsecutiveTwos > maxConsecutiveTwos) 
    {
        maxConsecutiveTwos = currentConsecutiveTwos;
    }

    std::cout << "Массив A: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << A[i] << " ";
    }
    std::cout << "\nМаксимальное количество подряд идущих двоек: " << maxConsecutiveTwos << std::endl;

    return 0;
}