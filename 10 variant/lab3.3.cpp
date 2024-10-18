/*
Задание 3. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Удалить все нули и единицы, если 
таковые имеются, и вывести измененный массив на экран. Дополнительные 
массивы использовать нельзя – меняем исходный массив с помощью сдвига 
элементов влево. Пример приведен в методичке. Сделать проверку на 
корректность ввода n
*/

#include <iostream>
#include <limits>

bool readPositiveIntAndCheckInput(int& input, const char* message) 
{
    bool validInput = false;
    do 
	{
        std::cout << message;
        if (!(std::cin >> input) || input <= 0 || input > 20) 
		{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a positive integer not exceeding 20.\n";
        } 
		else 
		{
            validInput = true;
        }
    } 
	while (!validInput);
    return validInput;
}

int main() 
{
    int n;
    if (!readPositiveIntAndCheckInput(n, "Enter the length of the array (not more than 20):")) 
	{
        return EXIT_FAILURE;
    }

    int numbers[n];
    std::cout << "Enter " << n << " integers separated by spaces:\n";

    for (int i = 0; i < n; ++i) 
	{
        std::cin >> numbers[i];
    }

    int shift = 0;
    for (int i = 0; i < n; ++i) 
	{
        if (numbers[i] == 0 || numbers[i] == 1) 
		{
            shift++;
        } 
		else 
		{
            numbers[i - shift] = numbers[i];
        }
    }

    n -= shift;

    std::cout << "Modified array after removing 0s and 1s: \n";
    for (int i = 0; i < n; ++i) 
	{
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
