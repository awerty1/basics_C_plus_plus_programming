/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Удвоить слово с заданным
номером (номер слова вводится; если такого слова нет, оставить строку без
изменения).
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
// объявление переменных
    string inputString;
    int wordNumber, currentWordIndex = 1;
    
    // ввод строки символов с помощью функции getline
    cout << "Введите строку символов: ";
    getline(cin, inputString);
    
    // ввод номера слова для удвоения
    cout << "Введите номер слова для удвоения: ";
    cin >> wordNumber;
    
    // инициализация переменных для текущего слова и результирующей строки
    string currentWord = "";
    string resultString = "";
    
    // цикл по символам входной строки
    for (int i = 0; i <= inputString.length(); i++)
    {
        if (inputString[i] == ' ' || i == inputString.length()) //если пробел или конец слова
        {
            // если текущее слово - слово для удвоения, то добавляем его в результирующую строку дважды
            if (currentWordIndex == wordNumber)
            {
                resultString += currentWord + " " + currentWord + " ";
            } 
            else // иначе добавляем его только один раз
            {
                resultString += currentWord + " ";
            }
            
            // переходим к следующему слову
            currentWordIndex++;
            currentWord = "";
        } 
        else // если символ не пробел, то добавляем его к текущему слову
        {
            currentWord += inputString[i];
        }
    }
    
    cout << "Результат: " << resultString;
    
    return 0;
}
