/*
Задание 1. Вводится строка произвольного текста. Вывести на экран все
согласные буквы из этой строки. Если таких букв нет, вывести -1.
*/

#include <iostream>
#include <string>

using namespace std; 

int main() 
{ 
	setlocale(LC_ALL, "Russian"); 
	
	string str; 
	cout << "Введите строку: "; 
	getline(cin, str); 
	bool tf = false; 
	
	for (char c : str) 
	{ 
		 //УЕЫАОЭЯИЮуеыаояию
		 if (isalpha(c) && !strchr("AEIOUaeiouYy", c)) 
		 { 
			 cout << c << "\t"; 
			 tf = true; 
		 } 
	} 
	
	if (!tf) 
	{	
		cout << "-1"; 
	} 
}
