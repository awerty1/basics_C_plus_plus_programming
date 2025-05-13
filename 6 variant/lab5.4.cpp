/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Удалить слово с заданным
номером (номер слова вводится; если такого слова нет, оставить строку без
изменения).
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() 
{
    string str;
    int del_number = 0;
    int num = 1;
    cout << "Введите строку: ";
    getline(cin, str); // считываем всю строку, включая пробелы
    
    do 
    {
        cout << "Введите номер удаляемого слова: ";
        
        if (!(cin >> del_number)) 
        {
            cout << "Ошибка ввода! Неправильный формат числа." << endl;
            cin.clear(); //очистка флага ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //очистка буфера ввода
        } 
        else 
        {
            //del_number--; //уменьшаем на 1, чтобы использовать как индекс массива
            
            if (del_number < 0) 
            {
                cout << "Ошибка! Номер должен быть больше 0." << endl;
            }
            else 
            {
                break; //выход из цикла, если введено корректное значение
            }
        }
    } while (true);


    
    string res = ""; // создаём новую строку для результата
    for (size_t i = 0; i < str.size(); i++) 
    {
		//if ((str[i] == ' ') || (isspace(str[i])))
		if(isspace(str[i]) && (i>0) && (!isspace(str[i-1])))
		{
			num++; // если текущий символ пробел/таб, то это следующее слово
		}
        
		//if (num != del_number || (num == del_number && i == str.size()-1)) 
		if(num != del_number || (num == del_number && i == str.size()))
		{
			res += str[i]; // копируем символ в новую строку, если это не удаляемое слово
		} 
// 		else if (num == del_number && i != str.size()) 
// 		{
// 			//while (i < str.size() && str[i+1] != ' ') 
// 			while (i < str.size() && !isspace(str[i+1])) 
// 				i++; // пропускаем символы до следующего пробела или табуляции
// 		}
    }
    
    
    cout << "Результат после удаления " << del_number << " слова:" << res << endl;
    
    return 0;
}
