/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
a) параметр функции – строка символов, представляющая из себя 
произвольное арифметическое выражение. Проверить баланс открывающихся и 
закрывающихся скобок (оформить как логическую функцию);
*/

#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& expression) 
{
    std::stack<char> s;
    
    for (char ch : expression) 
    {
        if (ch == '(') 
        {
            s.push(ch);
        } 
        else if (ch == ')')
        {
            if (s.empty() || s.top() != '(') 
            {
                return false; // Если нет соответствующей открывающей скобки
            }
            s.pop();
        }
    }
    
    return s.empty(); // Если стек пуст, то баланс скобок соблюден
}

int main() {
    std::string expressions[] = {
        "((a + b) * c)",
        "((a + b)) * c)",
        "(a + b) * (c + d)",
        "((a + b) * (c + d)",
        "((a + b) * (c + d))"
    };

    for (const std::string& expr : expressions) 
    {
        std::cout << "Expression: \"" << expr << "\" is ";
        if (isBalanced(expr)) 
        {
            std::cout << "balanced." << std::endl;
        } 
        else 
        {
            std::cout << "not balanced." << std::endl;
        }
    }

    return 0;
}