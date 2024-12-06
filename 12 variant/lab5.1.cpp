/*
Задание 1. Вводится строка произвольного текста. Заменить все строчные
буквы на заглавные. Если в строке нет строчных букв, оставить строку без
изменений. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string inputString;
    
    std::cout << "Введите строку текста: ";
    std::getline(std::cin, inputString);
    
    bool hasLowerCase = false;
    
    for (char& c : inputString) {
        if (std::islower(c)) {
            hasLowerCase = true;
            c = std::toupper(c);
        }
    }
    
    if (hasLowerCase) {
        std::cout << "Преобразованная строка: " << inputString << std::endl;
    } else {
        std::cout << "Строка без изменений: " << inputString << std::endl;
    }
    
    return 0;
}