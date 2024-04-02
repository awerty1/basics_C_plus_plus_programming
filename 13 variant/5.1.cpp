/*
Задание 1. Вводится строка произвольного текста. Заменить все заглавные
буквы на строчные. Если в строке нет строчных букв, оставить строку без
изменений. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Введите строку:";
    getline(std::cin, str);
    
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    std::cout << "Строка после преобразования:" << str;
    return 0;
}
