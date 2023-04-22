/*
Задание 1. Вводится строка произвольного текста. Вывести на экран все
знаки препинания. Если знаков препинания нет в строке, вывести -1.

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string text;
    cout << "Введите строку: ";
    getline(cin, text); // ввод строки
    
    int punct_count = 0; // счетчик знаков препинания
    char punct_arr[text.length()]; // массив для хранения знаков препинания

    for (size_t i = 0; i < text.length(); i++)
    {
        if (ispunct(text[i]))
        {
            // добавляем знак препинания в массив
            punct_arr[punct_count] = text[i]; 
            // увеличиваем счетчик знаков препинания
            punct_count++; 
        }
    }
    
    // сортировка, чтобы в будущем удалить повторяющиеся элементы
    sort(punct_arr, punct_arr+punct_count);
    
    cout << "Спец символы после сортировки: ";
    size_t index = 0;
    for(auto& elem : punct_arr)
    {
        cout << "'" << elem << "'";
    
        // Если элемент не последний, то ставим запятую
        if (index != punct_count - 1)
        {
            cout << " , ";
        }
        index++;
    }
    cout << endl;
    
    
    // если знаков препинания нет, выводим -1
    if (!punct_count)
    {
        cout << "-1";
    }
    else
    {

        // удаление повторяющихся спец символов из массива char
        for (size_t i = 0; i < punct_count; i++)
        {
            for (size_t j = i+1; j < punct_count; ++j)
            {
                if (punct_arr[j] == punct_arr[i])
                {
                    for (size_t k = j; k < punct_count; k++)
                    {
                        punct_arr[k] = punct_arr[k+1];
                    }
                    --punct_count;
                    --i;
                }
            }
        }
        
        // Вывод элементов на экран
        cout << "Спец символы из строки: ";
        for (size_t i = 0; i < punct_count; i++)
        {
            cout << "'" << punct_arr[i] << "'";
    
            // Если элемент не последний, то ставим запятую
            if (i != punct_count - 1)
            {
                cout << " , ";
            }
        }

    }
    
    return 0;
}