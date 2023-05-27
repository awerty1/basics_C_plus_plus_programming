/*
Вводится строка произвольного текста на русском языке. Заменить в ней все буквы "а"
на буквы "о". Подсчитать количество замен
*/

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string text;
    int count = 0; // переменная для хранения количества замен

    cout << "Введите текст: ";
    getline(cin, text);

    for (int i = 0; i < text.length(); i++) 
    {
        if (tolower(text[i]) == 'a')
        {
            text[i] = 'o';
            count++;
        }
    }

    cout << "Измененный текст: " << text << endl;
    cout << "Количество замен: " << count << endl;

    return 0;
}

