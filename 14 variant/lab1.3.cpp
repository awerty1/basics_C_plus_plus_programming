/*
Задание 3. Написать программу проверки знания истории архитектуры. 
Программа должна вывести вопрос и три варианта ответа. Пользователь должен 
выбрать ответ и ввести его номер. В случае правильного ответа на экране 
появляется сообщение «Вы ответили правильно», в случае неверного выводится
правильный ответ.
*/

#include <iostream>
#include <limits>

void askQuestion(const std::string& question, const std::string& option1, 
                const std::string& option2, const std::string& option3, int correctAnswer) 
{
    std::cout << question << std::endl;
    std::cout << "1. " << option1 << std::endl;
    std::cout << "2. " << option2 << std::endl;
    std::cout << "3. " << option3 << std::endl;

    int userAnswer;
    std::cout << "\nВведите номер выбранного варианта ответа: ";
    while (!(std::cin >> userAnswer) || userAnswer < 1 || userAnswer > 3) 
    {
        std::cout << "Ошибка ввода. Введите корректный номер выбранного варианта ответа: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (userAnswer == correctAnswer) 
    {
        std::cout << "Вы ответили правильно! 😄" << std::endl;
    } 
    else 
    {
        std::cout << "Вы ответили неправильно. Правильный ответ: " << correctAnswer << " 😕" << std::endl;
    }
}

int main() 
{
    // Задаем вопрос №1
    std::string question1 = "Кто является автором Эйфелевой башни?";
    std::string option1_1 = "Антонио Гауди";
    std::string option1_2 = "Гюстав Эйфель";
    std::string option1_3 = "Леонардо да Винчи";
    int correctAnswer1 = 2;

    askQuestion(question1, option1_1, option1_2, option1_3, correctAnswer1);

    // Задаем вопрос №2
    std::string question2 = "\nКакое здание является символом Сиднея, Австралия?";
    std::string option2_1 = "Лувр";
    std::string option2_2 = "Опера Харбор";
    std::string option2_3 = "Большой каньон";
    int correctAnswer2 = 2;

    askQuestion(question2, option2_1, option2_2, option2_3, correctAnswer2);

    // Задаем вопрос №3
    std::string question3 = "\nКто разработал теорию функционального стиля в архитектуре?";
    std::string option3_1 = "Людвиг Мис ван дер Роэ";
    std::string option3_2 = "Ле Корбюзье";
    std::string option3_3 = "Франк Ллойд Райт";
    int correctAnswer3 = 2;

    askQuestion(question3, option3_1, option3_2, option3_3, correctAnswer3);

    return 0;
}