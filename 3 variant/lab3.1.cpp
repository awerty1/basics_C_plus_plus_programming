/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -50 до 50 (число n вводится с клавиатуры, его значение не больше 20). Найти 
разность наибольшего и наименьшего чисел в этом массиве. Сделать проверку 
на корректность ввода n.
*/

#include <iostream>
#include <random>
#include <stdexcept>

int main()
{
    int n;
    
    while (true)
    {
        std::cout << "Enter the number n (not greater than 20): ";
        std::cin >> n;
        
        try
        {
            if (std::cin.fail())
            {
                std::cin.clear();  // Clear the input error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
                throw std::invalid_argument("Invalid input. Please enter a number.");
            }
            
            if (n <= 0 || n > 20)
            {
                throw std::out_of_range("Invalid value for n. Please enter a number from 1 to 20.");
            }
            
            break;  // Exit the loop if the input is valid
            
        }
        catch (const std::exception& ex)
        {
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    
    // The rest of the code remains the same
    
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(-50, 50);
    
    // Create and fill an array A with random numbers
    int *A = new int[n];
    std::cout << "Array elements: ";
    for (int i = 0; i < n; ++i)
    {
        A[i] = distribution(gen);
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    
    // Find the largest and smallest numbers in the array
    int minNum = A[0];
    int maxNum = A[0];
    for (int i = 1; i < n; ++i)
    {
        if (A[i] < minNum)
        {
            minNum = A[i];
        }
        if (A[i] > maxNum)
        {
            maxNum = A[i];
        }
    }
    
    // Calculate the difference between the largest and smallest numbers
    int difference = maxNum - minNum;
    
    // Output the result
    std::cout << "Largest number: " << maxNum << std::endl;
    std::cout << "Smallest number: " << minNum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    
    delete[] A;
    
    return 0;
}
