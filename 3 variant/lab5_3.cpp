/*
Задание 3. Вводится строка символов. Определить количество букв в
первом слове. Предусмотреть вариант, когда в начале строки есть пробелы.
*/

//string input | строковый класс | Для вводимой строки
//int i | целый тип | Сетчик цикла
//int count|целый тип| для подсчета количества букв


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int count = 0;
    
    cout << "Введите строку: "; 
    getline(cin, input);
    
    // удаляем пробелы в начале строки
    input.erase(0, input.find_first_not_of(' '));
    // удаляем табы в начале строки
    input.erase(0, input.find_first_not_of('\t'));
    
    // считаем количество букв в первом слове
    for(int i = 0; i < input.length(); i++)
    {
        //если находим пробел или таб в строке, то выходим
        if(input[i] == ' ' || input[i] == '\t')
        {
            break;
        }
        // иначе считаем символы
        count++;
    }
    
    cout << "Количество букв в первом слове: " << count << endl;
    
    return 0;
}