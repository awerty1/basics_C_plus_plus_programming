/*
* Найти числа из промежутка от А до В, у которых больше всего делителей
*/


#include <iostream>

int countDivisors(int num) 
{
    int count = 0;
    for (int i = 1; i <= num; i++) 
    {
        if (num % i == 0) 
        {
            count++;
        }
    }
    return count;
}

int findNumberWithMaxDivisors(int start, int end) 
{
    int maxDivisors = 0;
    int numberWithMaxDivisors = 0;
    
    for (int i = start; i <= end; i++) 
    {
        int divisors = countDivisors(i);
        
        if (divisors > maxDivisors) 
        {
            maxDivisors = divisors;
            numberWithMaxDivisors = i;
        }
    }
    
    return numberWithMaxDivisors;
}

int main() 
{
    int A, B;
    std::cout << "Введите промежуток A и B: ";
    std::cin >> A >> B;
    
    int result = findNumberWithMaxDivisors(A, B);
    
    std::cout << "Число с наибольшим количеством делителей: " << result << std::endl;
    
    return 0;
}