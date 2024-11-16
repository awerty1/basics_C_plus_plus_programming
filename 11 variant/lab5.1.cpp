/*
Задание 1. Вводится строка произвольного текста. Заменить все цифры на
букву а. Если в строке нет цифр, оставить строку без изменений. Вывести
преобразованную таким образом строку.
*/

//variant of lab #1
/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cout << "Введите строку: ";  
	getline(cin, str);

	for(int i=0; i<str.size(); ++i)
	{
		if(isdigit(str[i]))
		{
			str[i] = 'a';
		}
	}

	cout << "Преобразованная строка: " << str << endl;

	return 0;
}
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string replaceDigitsWithA(string str)
{
    for(int i=0; i<str.size(); ++i)
    {
        if(isdigit(str[i]))
        {
            str[i] = 'a';
        }
    }
        return str;
}
    
int main()
{
    // Test Case 1
    string str1 = "a1b2c3d4e5f6g7h8i9j0";
    string expected1 = "aabacadaeafagahaiaja";
    assert(replaceDigitsWithA(str1) == expected1);
    
    // Test Case 2
    string str2 = "Hello world!";
    string expected2 = "Hello world!";
    assert(replaceDigitsWithA(str2) == expected2);
    
    // Test Case 3
    string str3 = "12345";
    string expected3 = "aaaaa";
    assert(replaceDigitsWithA(str3) == expected3);
    
    cout << "All test cases passed!" << endl;
    
    return 0;
}