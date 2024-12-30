/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами, причем слова могут
разделяться более чем одним пробелом, в начале и конце строки пробелы также
допускаются. Удвоить согласные буквы в предпоследнем слове введенной
строки. Если в строке только одно слово или совсем нет слов – оставить строку
без изменения. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <cstring>
#include <cctype>

bool isConsonant(char ch) 
{
	return std::isalpha(ch) && !strchr("AEIOUaeiou", ch);
}

void doubleConsonantsInPenultimateWord(std::string& sentence) 
{
	std::string penultimateWord;
	bool foundPenultimate = false;

	std::string word;
	for (char ch : sentence) 
	{
		if (std::isspace(ch)) 
		{
			if (!word.empty()) 
			{
				penultimateWord = word;
				foundPenultimate = true;
				word.clear();
			}
		} 
		else 
		{
			word += ch;
		}
	}

	if (foundPenultimate) 
	{
		std::string doubledWord;
		for (char c : penultimateWord) 
		{
			doubledWord += c;
			if (isConsonant(c)) 
			{
				doubledWord += c;
			}
		}

		size_t pos = sentence.find(penultimateWord);
		if (pos != std::string::npos) 
		{
			sentence.replace(pos, penultimateWord.length(), doubledWord);
		}
	}
}

int main() 
{
	std::string sentence;
	std::cout << "Введите строку с несколькими словами: ";
	std::getline(std::cin, sentence);

	doubleConsonantsInPenultimateWord(sentence);

	std::cout << "Преобразованная строка: " << sentence << std::endl;

	return 0;
}