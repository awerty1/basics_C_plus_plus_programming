/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
c) возвратить позицию первого символа операции (+, -, *, /, %), который 
встретился в строке (нумерация позиций должна начинаться с единицы). 
Параметры – строка и символ. Если таких символов в строке нет, возвратить 0.
*/

#include <iostream>
#include <string>

int findFirstOperation(const std::string& expression, char operation) 
{
    // Проходим по каждому символу строки
    for (size_t i = 0; i < expression.length(); ++i) 
    {
        if (expression[i] == operation) 
        {
            return static_cast<int>(i + 1); // Возвращаем позицию (с 1)
        }
    }
    return 0; // Если не найдена, возвращаем 0
}

int main() 
{
    std::string expressions[] = {
        "3 + 5 * (2 - 8) / 4",
        "a - b + c * d / e",
        "no operations here",
        "10 % 3 = 1",
        "(* &"
    };

    char operations[] = {'+', '-', '*', '/', '%'};

    for (const std::string& expr : expressions) 
    {
        std::cout << "Expression: \"" << expr << "\"" << std::endl;

        for (char op : operations) 
        {
            int position = findFirstOperation(expr, op);
            if (position != 0) 
            {
                std::cout << "First occurrence of '" << op << "' is at position: " << position << std::endl;
            } 
            else 
            {
                std::cout << "Character '" << op << "' is not found." << std::endl;
            }
        }

        std::cout << std::endl; // Пустая строка для разделения выражений
    }

    return 0;
}