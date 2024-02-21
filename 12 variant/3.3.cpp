/*
Задание 3. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Вставить число перед элементами, 
кратными 2, если таковые имеются. Число для вставки вводится с клавиатуры. 
Вывести измененный массив на экран. Дополнительные массивы использовать 
нельзя – меняем исходный массив с помощью сдвига элементов. Пример 
приведен в методичке. Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <limits>

const int MAX_SIZE = 20;

int main() 
{
    int n;
    
    do 
    {
        std::cout << "Введите размер массива (не больше 20): ";
        std::cin >> n;
        
        // Очищаем буфер перед вводом числа для вставки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (std::cin.fail()|| n <= 0 || n > MAX_SIZE) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число от 1 до 20.\n";
        }
    }
    while (n <= 0 || n > MAX_SIZE || std::cin.fail());
    

    int arr[MAX_SIZE];
    std::cout << "Введите " << n << " целых чисел в массив:";
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i];
        
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
            --i;
        }
    }


    int numberToInsert;
    bool validInput = false;
    
    do
    {
        
        std::cout << "Введите число для вставки перед элементами, кратными 2: ";
        
        
        
        if (std::cin >> numberToInsert) 
        {
            validInput = true;
            // Очищаем буфер перед вводом числа для вставки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
        }
    } 
    while (!validInput);
    

    for (int i = 0; i < n; ++i) 
    {
        if ((arr[i] % 2 == 0) && (arr[i] != 0)) 
        {
            for (int j = n; j > i; --j) 
            {
                arr[j] = arr[j - 1];
            }
            arr[i] = numberToInsert;
            ++n;
            ++i; // Учтем вставленный элемент
        }
    }

    std::cout << "Измененный массив:\n";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
