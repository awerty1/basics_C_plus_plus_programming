/*
Вычисление делителей для заданного числа
*/

#include <iostream>

int findDivisors(int n) 
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    
    return count;
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Number of divisors: " << findDivisors(n);
    return 0;
}
