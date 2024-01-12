/*
Задание 2. Вводится строка произвольного текста. Удалить все цифры в
этой строке. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string input, output;
    cout << "Введите строку: ";
    getline(cin, input); // читаем строку
    
    // проходимся по каждому символу строки
    for (char c : input) 
    { 
        // если символ не является цифрой
        if (!isdigit(c)) 
        { 
            output += c; // добавляем его в выходную строку
        }
    }
    

    cout << "Строка после преобразования: " << output << endl; // выводим результат
    return 0;
}