/*
Задание 2. С клавиатуры вводится число n (от 1 до 6 цифр). Вывести на 
экран «yes», если число является палиндромом, и «no» в противном случае.
Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str)
{
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return (str == reversed);
}

int main()
{
    int n;
    std::string input;
    bool validInput = false;
    
    do
    {
        std::cout << "Input a number from 1 to 999999: ";
        std::cin >> input;
        
        try
        {
            n = std::stoi(input);
            if (n >= 1 && n <= 999999)
            {
                validInput = true;
            }
            else
            {
                std::cout << "Invalid input. Please enter a number from 1 to 999999." << std::endl;
            }
        }
        catch (std::invalid_argument const&)
        {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
        catch (std::out_of_range const&)
        {
            std::cout << "Invalid input. Please enter a number from 1 to 999999." << std::endl;
        }

    }
    while (!validInput);
    
    std::string strNum = std::to_string(n);
    
    if (isPalindrome(strNum))
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }
    
    return 0;
}
