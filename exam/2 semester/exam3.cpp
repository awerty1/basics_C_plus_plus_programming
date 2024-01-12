/*
Данная программа запрашивает у пользователя две строки, сравнивает их и выводит результат сравнения 
в консоль. Если строки имеют разную длину, программа выводит сообщение "Строки имеют разную длину". 
Если все символы в двух строках совпадают, программа выводит сообщение "Несовпадающих нет". 
В противном случае программа выводит сообщение о том, что символ в позиции i+1 не совпадает.
*/

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

int main()

{
    setlocale(LC_ALL, "Russian");
    string strinG, strinGG;
    cout << "Введите строку1: ";
    getline(cin, strinG);
    cout << "Введите строку2: ";
    getline(cin, strinGG);

    int i = 0;
    for (; i < strinG.length(); i++)
    {
        if (strinG[i] != strinGG[i])
        {
            break;
            
        }
    }

    if (strinG.empty() || strinGG.empty())
    {
        cout << "Вы не ввели строку!";
    }
    else if (strinG.length() != strinGG.length())
    {
        cout << "Строки имеют разную длину";
    }
    else if (i == strinG.length())
    {
        cout << "Несовпадающих нет";
    }
    else
    {
        cout << "Символ в позиции " << i + 1 << " не совпадает";
    }

}