/*
Задание 1. Составить программу нахождения суммы чётных чисел,
находящихся в промежутке от 25 до 55.
*/

#include <iostream>

int main()
{
    int sum = 0;
    
    // Iterate over numbers from 25 to 55
    for (int num = 25; num <= 55; num++)
    {
        // Check if the number is even
        if (num % 2 == 0)
        {
            // If the number is even, add it to the sum
            sum += num;
        }
    }
    
    // Output the result
    std::cout << "Sum of even numbers: " << sum << std::endl;

    return 0;
}
