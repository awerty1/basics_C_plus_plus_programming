/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
b) удалить из заданной строки фрагменты, заключенные в скобки (скобки 
могут быть вложенными). Если баланс скобок нарушен, оставить строку без 
изменения тип функции void, все изменения выполнять в строке, которая 
является параметром функции;
*/

#include <iostream>
#include <stack>
#include <string>

void removeBrackets(std::string& expression) 
{
    std::stack<int> s;
    std::string result;
    bool isBalanced = true;

    // Проходим по каждому символу строки
    for (int i = 0; i < expression.size(); ++i) 
    {
        char ch = expression[i];

        if (ch == '(') 
        {
            s.push(i); // Запоминаем индекс открывающей скобки
        } 
        else if (ch == ')') 
        {
            if (s.empty()) 
            {
                isBalanced = false; // Найдена закрывающая скобка без открывающей
                break;
            }
            s.pop(); // Удаляем соответствующую открывающую скобку
        } 
        else 
        {
            // Если не в скобках, добавляем в результат
            if (s.empty()) 
            {
                result += ch;
            }
        }
    }

    // Проверка на баланс скобок
    if (isBalanced && s.empty()) 
    {
        expression = result; // Обновляем строку, если скобки сбалансированы
    }
}

int main() 
{
    std::string expressions[] = {
        "((a + b) * c) + d",
        "((a + (b * c)) + d)",
        "(a + b) * c)",
        "((a + b) * (c + d)) + (e + f)",
        "a + b * c"
    };

    for (std::string& expr : expressions) 
    {
        std::cout << "Original expression: \"" << expr << "\"" << std::endl;
        
        removeBrackets(expr);
        
        std::cout << "Modified expression: \"" << expr << "\"" << std::endl;
    }

    return 0;
}