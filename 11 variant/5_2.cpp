/*
Задание 2. Вводится строка произвольного текста. Удалить все буквы в
этой строке. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    char str[1000];
    int len, i, j;
    
    cout << "Введите строку произвольного текста: ";
    cin.getline(str, 1000);
    
    len = strlen(str);
    
    // Удаляем все буквы
    for(i = 0, j = 0; i < len; ++i) 
    {
        if (!isalpha(str[i])) 
        {
            str[j++] = str[i];
        }
    }
    
    // Добавляем завершающий нуль-символ
    str[j] = '\0';
    
    // Выводим преобразованную строку
    cout << "Преобразованная строка: " << str << endl;
    
    return 0;
}