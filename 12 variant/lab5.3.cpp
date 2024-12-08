/*
Задание 3. Вводятся две строки произвольного текста. Найти количество
несовпавших символов, находящихся на одних и тех же позициях в разных
строках
*/

#include <iostream>
#include <string>

int main() {
    std::string firstString, secondString;
    int nonMatchingCount = 0;
    
    std::cout << "Введите первую строку: ";
    std::getline(std::cin, firstString);
    
    std::cout << "Введите вторую строку: ";
    std::getline(std::cin, secondString);
    
    // Найдем минимальную длину из двух строк
    size_t minLen = std::min(firstString.length(), secondString.length());
    
    // Посчитаем количество несовпавших символов на одинаковых позициях
    for (size_t i = 0; i < minLen; ++i) 
	{
        if (firstString[i] != secondString[i]) 
		{
            nonMatchingCount++;
        }
    }
    
    std::cout << "Количество несовпавших символов: " << nonMatchingCount << std::endl;
    
    return 0;
}