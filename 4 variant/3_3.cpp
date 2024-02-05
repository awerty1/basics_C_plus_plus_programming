/*
Задание 3. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Удалить все элементы, кратные 2, если 
таковые имеются, и вывести измененный массив на экран. Дополнительные 
массивы использовать нельзя – меняем исходный массив с помощью сдвига 
элементов влево. Пример приведен в методичке. Сделать проверку на 
корректность ввода n.
*/

#include <iostream>
#include <random>

int main()
{
    // Ввод количества элементов массива
    int n;
    bool wrong_input = false; // Флаг для проверки корректности ввода

    do 
	{
        std::cout << "Введите количество элементов массива (не больше 20): ";

        if (!(std::cin >> n))
        {
            std::cin.clear(); // Очищаем флаг ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Пропускаем все символы до конца строки
            std::cout << "Некорректный ввод. Пожалуйста, введите число от 1 до 20." << std::endl;
            wrong_input = true;
        }
        else
        {
            if (n <= 0 || n > 20)
            {
                std::cout << "Некорректный ввод. Пожалуйста, введите число от 1 до 20." << std::endl;
                wrong_input = true;
            }
            else
            {
                wrong_input = false;
            }
        }
    } 
	while (wrong_input);


    // Создание и заполнение массива случайными числами
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int* array = new int[n];
    for (int i = 0; i < n; ++i)
    {
        array[i] = dis(gen);
    }

    // Вывод исходного массива
    std::cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Удаление элементов, кратных 2, с помощью сдвига элементов массива влево
    int newSize = n;
    for (int i = 0; i < newSize; ++i)
    {
        if (array[i] % 2 == 0)
        {
            for (int j = i; j < newSize - 1; ++j)
            {
                array[j] = array[j + 1];
            }
            --newSize;
            --i; // Проверяем текущий элемент еще раз
        }
    }

    // Вывод измененного массива
    std::cout << "Измененный массив: ";
    for (int i = 0; i < newSize; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array;

    return 0;
}