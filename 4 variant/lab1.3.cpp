/*
Задание 3. Даны два числа M и N. Меньшее из этих двух чисел заменить их 
полусуммой, а большее – их удвоенным произведением. Вывести полученные 
значения. Отдельно рассмотреть случай ввода одинаковых значений.
*/

#include <iostream>

int main() 
{
    int m, n;
    std::cout << "Введите два числа: ";
    std::cin >> m >> n;
    
    if (m == n)
    {
        // оба числа равны
        int result = m + n;
        std::cout << "Результат: " << result << std::endl;
    }
    else
    {
        // числа разные
        int smaller = (m < n) ? m : n;
        int larger = (m > n) ? m : n;
        
        int halfSum = (m + n) / 2;
        int doubleProduct = 2 * m * n;
        
        std::cout << "Меньшее значение: " << halfSum << std::endl;
        std::cout << "Большее значение: " << doubleProduct << std::endl;
    }
    
    return 0;
}
