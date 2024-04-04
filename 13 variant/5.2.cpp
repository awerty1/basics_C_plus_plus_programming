/*
Задание 2. Вводится строка произвольного текста. Удвоить все цифры в
этой строке. Вывести преобразованную таким образом строку
*/

#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Введите строку:";
    getline(std::cin, str);
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        int num = c - '0';
        if (num >= 0 && num <= 9) {
            str = str.substr(0, i + 1) + std::to_string(num) + str.substr(i + 1);
            ++i;
        }
    }
    std::cout << "Строка после преобразования: " << str;
	
    return 0;
}