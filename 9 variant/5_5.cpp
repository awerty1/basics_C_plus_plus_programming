/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. В третьем слове, если оно
есть, поменять местами первый символ с последним. Вывести преобразованную
таким образом строку.
*/

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
//задача 5
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string str, a = "";
    char c = ' ';
    getline(cin,str);
    vector<string> mass;
    str = str + " ";
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
        if (i == 2)
        {
            c = mass.at(i).back();
            mass.at(i).back() = mass.at(i).front();
            mass.at(i).front() = c;
        }
        cout << mass.at(i) << " ";
    }
    
    if (isblank(c))
    {
        cout << "\nНет третьего слова!";
    }
}
