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

bool isBalanced(const std::string& expression) 
{
    std::stack<char> brackets;

    for (char ch : expression) 
    {
        if (ch == '(' || ch == '[' || ch == '{') 
        {
            brackets.push(ch);
        } 
        else if (ch == ')' || ch == ']' || ch == '}') 
        {
            if (brackets.empty()) 
            {
                return false;  // Найдена закрывающаяся скобка без соответствующей открывающейся
            }

            char top = brackets.top();
            brackets.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) 
                {
                    return false;  // Несоответствие типов скобок
                }
        }
    }

    return brackets.empty();  // Если стек пуст, то все скобки сбалансированы
}

int main() 
{
    std::string expression;
    std::cout << "Введите арифметическое выражение: ";
    std::getline(std::cin, expression);
    
    if (expression.empty())
    {
        std::cout << "Выражение не содержит скобок." << std::endl;
    }
    else if (isBalanced(expression)) 
    {
        std::cout << "Скобки сбалансированы." << std::endl;
    } 
    else 
    {
        std::cout << "Скобки не сбалансированы." << std::endl;
    }

    return 0;
}