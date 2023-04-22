/*
Задание 3. Вводится строка символов. Определить количество букв в
последнем слове. Предусмотреть вариант, когда в конце строки есть пробелы.
*/

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str;
    int count = 0;
    
    cout << "Введите строку: ";
    getline(cin, str);
    
    // Определяем индекс последнего символа
    int last_index = str.length() - 1;
    
    // Избегаем пробелы в конце строки
    //МОНСТР :O
    //while (last_index >= 0 && (str[last_index] == ' ' || str[last_index] == '\t'))
    //last_index--
    
    //isspace - проверяет, является ли символ пробелом, 
    //табуляцией, переходом на новую строку и т.д.
    while (last_index >= 0 && isspace(str[last_index]))
                    last_index--;
    
    // Считаем количество символов в последнем слове
    for (auto i = last_index; i >= 0; i--) 
    {
        //if (str[i] == ' ' || str[i] == '\t')
        if(isspace(str[i]))
        {
            break;
        }
        
        count++;
    }
    
    
    if(str.empty())
    {
        cout << "Введена пустая строка!";
    }
    else
    {
        cout << "Количество букв в последнем слове: " << count;
    }
    
    
    // bug таб
    
    return 0;
}