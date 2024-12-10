/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами, причем слова могут
разделяться более чем одним пробелом, в начале и конце строки пробелы также
допускаются. Удалить гласные буквы в предпоследнем слове введенной строки.
Если в строке только одно слово или совсем нет слов – оставить строку без
изменения. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>
#include <cctype>

bool isVowel(char c) 
{
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() 
{
    std::string inputString, resultString;
    
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);
    
    std::string word;
    std::string prePreviousWord;
    bool found = false;
    
    for (char c : inputString) 
	{
        if (std::isspace(c)) 
		{
            if (!word.empty()) 
			{
                if (found) 
				{
                    resultString += prePreviousWord + " ";
                    found = false;
                } 
				else 
				{
                    resultString += word + " ";
                    prePreviousWord = word;
                    found = true;
                }
            }
            word.clear();
        } 
		else 
		{
            word += c;
        }
    }
    
    if (!word.empty() && found) 
	{
        resultString += prePreviousWord + " " + word;
    } 
	else if (!word.empty()) 
	{
        resultString += word;
    }
    
    for (char& c : resultString) 
	{
        if (isVowel(c)) 
		{
            c = ' ';
        }
    }
    
    std::cout << "Результат: " << resultString << std::endl;
    
    return 0;
}