/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран все слова,
состоящие из трех букв
*/

/*#variant of lab 1
#include <iostream>
#include <cstring>

int main()
{
    char str[100];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 100);
    
    char* ptr = std::strtok(str, " ");
    while (ptr != nullptr)
    {
        if (std::strlen(ptr) == 3)
        {
            std::cout << ptr << std::endl;
        }
        
        ptr = std::strtok(nullptr, " ");
    }

    return 0;
}
*/

/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран все слова,
состоящие из трех букв.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    string input;
    getline(cin, input); // считываем входную строку
    
    vector<string> words; // создаем вектор, в котором будем хранить слова
    
    // разбиваем строку на слова
    size_t startPos = 0;
    while (true) 
    {
        size_t spacePos = input.find(' ', startPos); // ищем следующий пробел
        if (spacePos == string::npos) 
        { // если это последнее слово, то выходим из цикла
            words.push_back(input.substr(startPos));
            break;
        }
        
        words.push_back(input.substr(startPos, spacePos - startPos)); // добавляем слово в вектор
        startPos = spacePos + 1;
    }
    
    // выводим слова, состоящие из трех букв
    for (const string& word : words) 
    {
        if (word.length() == 3) 
        {
            cout << word << endl;
        }
    }

    return 0;
}