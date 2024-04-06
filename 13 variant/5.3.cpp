/*
Задание 3. С клавиатуры вводится строка символов, представляющая из
себя произвольное арифметическое выражение. Проверить баланс
открывающихся и закрывающихся скобок. Вывести каких скобок больше, если
баланс не соблюден. Предусмотреть вариант, когда скобки в выражении
отсутствуют.
*/

#include <iostream>
#include <stack>
#include <string>

bool checkBracketsBalance(const std::string& expression) 
{
	std::stack<char> bracketsStack;

	for (char ch : expression) 
	{
		if (ch == '(' || ch == '[' || ch == '{') 
		{
			bracketsStack.push(ch);
		} 
		else if (ch == ')' || ch == ']' || ch == '}') 
		{
			if (bracketsStack.empty()) 
			{
				return false; // Найдена закрывающаяся скобка, когда стек пустой
			}

			char top = bracketsStack.top();
			bracketsStack.pop();

			if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) 
			{
				return false; // Несоответствие открывающихся и закрывающихся скобок
			}
		}
	}

	return bracketsStack.empty();
}

int main() 
{
	std::string expression;
	std::cout << "Введите арифметическое выражение: ";
	std::getline(std::cin, expression);

	if (checkBracketsBalance(expression)) 
	{
		std::cout << "Баланс скобок соблюден." << std::endl;
	} 
	else 
	{
		std::cout << "Баланс скобок не соблюден." << std::endl;
	}

	return 0;
}