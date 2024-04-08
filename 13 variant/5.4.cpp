/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Поменять местами первое и
последнее слова. Вывести преобразованную таким образом строку.

*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void swapFirstAndLastWords(std::string& sentence) 
{
	std::stringstream ss(sentence);
	std::vector<std::string> words;
	std::string word;

	while (ss >> word) 
	{
		words.push_back(word);
	}

	if (words.size() >= 2) 
	{
		std::swap(words.front(), words.back());

		sentence.clear();
		for (const std::string& w : words) 
		{
			sentence += w + " ";
		}
		sentence.pop_back(); // Удаление лишнего пробела в конце строки
	}
}

int main() 
{
	std::string sentence;
	std::cout << "Введите строку с несколькими словами: ";
	std::getline(std::cin, sentence);

	swapFirstAndLastWords(sentence);

	std::cout << "Преобразованная строка: " << sentence << std::endl;

	return 0;
}