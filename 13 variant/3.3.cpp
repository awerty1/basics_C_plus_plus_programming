/*
Задание 3. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Вставить число до и после первого 
отрицательного элемента, если таковой имеется. Число для вставки вводится с 
клавиатуры. Вывести измененный массив на экран. Дополнительные массивы 
использовать нельзя – меняем исходный массив с помощью сдвига элементов. 
Пример приведен в методичке. Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <limits>

int main() 
{
    int n;
    bool inputValid = false;

    do 
    {
        std::cout << "Введите размер массива (не больше 20): ";
        if (!(std::cin >> n) || n <= 0 || n > 20) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Пожалуйста, введите целое число от 1 до 20.\n";
        } 
        else 
        {
            inputValid = true;
        }
    } 
    while (!inputValid);

    int arr[20];
    for (int i = 0; i < n; i++) 
    {
        std::cout << "Введите элемент массива " << i+1 << ": ";
        std::cin >> arr[i];
    }

    int numberToInsert;
    std::cout << "Введите число для вставки: ";
    std::cin >> numberToInsert;



    bool isNegativeFound = false;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] < 0) 
        {
            isNegativeFound = true;
            // Сдвигаем элементы вправо начиная со следующего после отрицательного
            for (int j = n; j > i; j--) 
            {
                arr[j] = arr[j - 1];
            }
            arr[i] = numberToInsert;
            n++;
            break; // Выходим из цикла, после вставки чисел до и после первого отрицательного
        }
    }
    
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] < 0) 
        {
            isNegativeFound = true;
            // Сдвигаем элементы вправо начиная со следующего после отрицательного
            for (int j = n; j > i + 1; j--) 
            {
                arr[j] = arr[j - 1];
            }
            arr[i+1] = numberToInsert;
            n++;
            break; // Выходим из цикла, после вставки чисел до и после первого отрицательного
        }
    }

    if (!isNegativeFound) 
    {
        std::cout << "В массиве отрицательные элементы отсутствуют.\n";
    } 
    else 
    {
        std::cout << "Измененный массив:\n";
        for (int i = 0; i < n; i++) 
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
