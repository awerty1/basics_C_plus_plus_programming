/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран все слова,
состоящие из меньше, чем n-букв (n вводится с клавиатуры). Например, n = 4,
тогда необходимо вывести все слова из одной, двух и трех букв.
*/

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string str, a = "";
    getline(cin,str);
    vector<string> mass;
    str = str + " ";
    cout << "Введите число n больше 0 ";
    int k = 0;
    do
    {
        cin >> k;
        if (k <= 0)
        {
            cout << "Число n должно быть больше 0 ";
        }
    } while (k <= 0);
    
    for (int i = 0; i<str.length(); i++)
    {
        if (isspace(str[i]) && !a.empty())
        {
            mass.push_back(a);
            a = "";
        }
        if(!isspace(str[i]))
            a = a + str[i];
    }
    
    for (int i = 0; i<mass.size(); i++)
    {
        if (mass.at(i).length() <= k)
        {
            cout << mass.at(i) << " ";
        }
    }
}
