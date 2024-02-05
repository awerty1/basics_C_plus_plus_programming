/*
Задание 3. Задан массив из n случайных целых чисел (число n вводится с
клавиатуры, его значение не больше 20). Удалить все элементы, кратные 2, если
таковые имеются, и вывести измененный массив на экран. Дополнительные
массивы использовать нельзя – меняем исходный массив с помощью сдвига
элементов влево. Пример приведен в методичке. Сделать проверку на
корректность ввода n.
*/

#include <iostream>
#include <array>
#include <limits>

int main()
{
    int n;
    
    do
    {
        // Ввод числа n
        std::cout << "Введите количество элементов массива (n): ";
        
        // Проверка корректности ввода n
        if (!(std::cin >> n))
        {
            std::cout << "Ошибка ввода!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (n <= 0 || n > 20)
        {
            std::cout << "Некорректный ввод n!" << std::endl;
        }
    }
    while (n <= 0 || n > 20);
    
    // Создание и заполнение массива случайными числами
    std::array<int, 20> arr{};
    std::cout << "Введите элементы массива: ";
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "M" << i+1 << ":";
        if (!(std::cin >> arr[i]))
        {
            std::cout << "Ошибка ввода символов!" << std::endl;
            
            // Очищаем входной буфер
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            // Уменьшаем счетчик, чтобы можно было повторно ввести значение
            i--;
        }
    }
    
    // Удаление элементов, кратных 2, и сдвиг массива влево
    int newSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    
    // Вывод измененного массива
    std::cout << "Измененный массив: ";
    for (int i = 0; i < newSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
