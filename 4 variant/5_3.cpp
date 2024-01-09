/*
Задание 3. Выяснить, является ли данное слово палиндромом (так
называются слова, читающиеся одинаково слева направо и справа налево,
например, потоп, наган).
*/

#include <iostream>
#include <algorithm>
#include <cctype>

bool isPalindrome(const std::string& word) 
{
    std::string processedWord;
    
    // Удаление знаков пунктуации и изменение регистра
    for (char c : word)
    {
        if (std::isalpha(c)) 
        {
            processedWord += std::tolower(c);
        }
    }
    
    // Проверка на палиндром
    std::string reversedWord = processedWord;
    std::reverse(reversedWord.begin(), reversedWord.end());
    
    return processedWord == reversedWord;
}

int main() 
{
    std::string word;
    std::cout << "Введите слово: ";
    std::getline(std::cin, word);
    
    if (word.empty())
    {
        std::cout << "Ошибка: введена пустая строка." << std::endl;
        return 0; // Завершаем программу
    }
    
    if (isPalindrome(word))
    {
        std::cout << "Данное слово является палиндромом." << std::endl;
    }
    else
    {
        std::cout << "Данное слово не является палиндромом." << std::endl;
    }
    
    return 0;
}
