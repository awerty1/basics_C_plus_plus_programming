/*
Задание 2. Вводится строка произвольного текста. Удалить все пробелы в
этой строке. Вывести преобразованную таким образом строку

*/

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str;
    cout << "Введите строку: ";
    getline(cin, str);
    bool found = false;
    

    for (size_t i = 0; i < str.length(); i++) 
    {
        //if (str[i] == ' ') 
        if (isspace(str[i]))
        {
            str.erase(i, 1);
            i--;
        }
        found = true;
    }
    
    if(!found || str.empty())
    {
        cout << "Введена пустая строка! :(" << str << endl;
    }
    else
    {
        cout << "Строка после удаления пробелов: " << str << endl;
    }
    
    //bug таб
    
    return 0;
}
