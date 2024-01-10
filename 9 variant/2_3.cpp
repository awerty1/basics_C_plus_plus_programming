/*
Задание 3. С клавиатуры вводится число n (от 1 до 6 цифр). Вывести на 
экран «yes», если число является палиндромом, и «no» в противном случае.
Сделать проверку на корректность ввода n.
*/

#include <iostream>

bool is_palindrome(int n)
{
    int rev = 0;
    int original = n;
    
    while (n > 0) 
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    
    return (original == rev);
}

int main()
{
    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    
    // Проверка на корректность ввода
    if (n <= 0 || n >= 1000000)
    {
        std::cout << "Ошибка ввода" << std::endl;
        return 0;
    }
    
    if (is_palindrome(n))
    {
        std::cout << "yes" << std::endl;
    } 
    else
    {
        std::cout << "no" << std::endl;
    }
    
    return 0;
}
