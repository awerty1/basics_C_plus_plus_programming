/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. «Перевернуть» второе слово,
т.е. перезаписать его наоборот. Вывести преобразованную таким образом
строку.
*/

#include <iostream>
#include <string>


int main() 
{
    std::string str;

    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    size_t firstSpacePos = str.find(' ');
    if (firstSpacePos != std::string::npos)
    {
        size_t secondSpacePos = str.find(' ', firstSpacePos + 1);
        std::string secondWord = str.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
    
        if (secondWord.length() > 1) 
        {
            for (int i = 0; i < secondWord.length() / 2 + secondWord.length() % 2; i++) 
            {
                std::swap(secondWord[i], secondWord[secondWord.length() - i - 1]);
            }
        }
        
        str.replace(firstSpacePos + 1, secondWord.length(), secondWord); 
    
        std::cout << "Преобразованная строка: " << str << std::endl;
    }
    else
    {
        std::cout << "В строке отсутствуют пробелы" << std::endl;
    }

    return 0;
}
