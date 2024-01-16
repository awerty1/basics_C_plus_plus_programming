/*
Задание 3. Написать программу проверки знания даты основания СанктПетербурга. В случае правильного ответа на экране появляется сообщение «Вы 
ответили правильно», в случае неверного выводится правильный ответ.
*/

#include <iostream>
#include <string>

int main() 
{
    int answer;
    const int correctAnswer = 1703;

    std::cout << "Когда был основан Санкт-Петербург? ";
    std::cin >> answer;

    if (answer == correctAnswer) 
    {
        std::cout << "Вы ответили правильно!\n";
    } 
    else 
    {
        std::cout << "Неправильный ответ. Правильная дата основания Санкт-Петербурга: " << correctAnswer << "\n";
    }

    return 0;
}



