/*
Задание 2. Вводится строка произвольного текста. Удалить из нее все
гласные буквы. Вывести преобразованную таким образом строку.
*/

//char str[81] |символьный тип| Создание массива символов из 81 элемента
//!!!!!!int has_space|целый тип| Не используется, можешь удалить из кода и не описывать в отчете
//const char vowels|символьный тип| Создание массива из гласных букв
//int len|целый тип| Получаем размер массива vowels
//int has_digit| целый тип| Счетчик, чтобы попасть на ветку исключения, если в строке нет цифр
//int i| целый тип| Сетчик цикла
//size_t i|беззнаковый целый тип| Сетчик цикла
//int has_symbols|целый тип| Для подсчета символов, нужен для исключения
//int k|целый тип| Используется при копировании сиволов
//bool isVowel|логический тип| Для функции, возвращает true если находит гласнуб букву, иначе возвращает false
//char c |символьный тип| Параметр функции

#include <iostream>

using namespace std;

bool isVowel(char c) 
{
    //гласные буквы
    const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    //узнаем размер
    int len = sizeof(vowels)/sizeof(vowels[0]);
    
    for(int i = 0; i < len; i++) 
    {
        // если переданный символ гласный в строчком или заглавном регистре
        if(c == vowels[i] || c == toupper(vowels[i])) 
        {
            return true;
        }
    }
    
    return false;
}

int main() 
{
    char str[81];
    int k = 0;
    int has_symbols = 0;
    size_t i;
    
    cout << "Введите строку: ";
    cin.getline(str, 81);
    

    for(i = 0; str[i] != '\0'; i++) 
    {
        if(!isVowel(str[i])) 
        {
            str[k] = str[i];
            k++;
            has_symbols++;
        }
    }
    
    str[k] = 0;
    
    
    if(!has_symbols)
    {
        cout << "Строка пуста" << endl;
    }
    else
    {
        cout << str << endl;
    }

    return 0;
}