/*
Задание 1. С клавиатуры вводятся длины сторон треугольника a, b, с. Найти 
и вывести биссектрисы треугольника, сторонами которого являются 
биссектрисы исходного треугольника.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

// Прототипы функций, требуются для препроцессора
double calculate_semiperimeter(double& a, double& b, double& c);
void find_bisectors(double& a, double& b, double& c, double* bisector_X, double& s);
void input_sides(double& side, char& side_name);


//тестовые даннные
//1 1 10
//0 0 0
//1 2 3

int main() 
{
    double a, b, c;
    // Название стороны для передачи в Функцию
    char side_A = 'A';
    char side_B = 'B';
    char side_C = 'C';
    
    
    input_sides(a, side_A);
    input_sides(b, side_B);
    input_sides(c, side_C);

    double bisector_X;
    double s = calculate_semiperimeter(a, b, c);
    try 
    {
        find_bisectors(a, b, c, &bisector_X, s);
        // std::fixed для вывода 2 знаков после запятой
        // std::setprecision(2) без std::fixed не будет работать
        std::cout << "Биссектриса к стороне А: " << std::fixed << std::setprecision(2) << bisector_X << std::endl;
    }
    catch (const std::string& error)
    {
        std::cout << "Ошибка: " << error << std::endl;
    }

    return 0;
}

// Вычисление полупериметра треугольника
double calculate_semiperimeter(double& a, double& b, double& c)
{
    return (a + b + c) / 2.0;
}

// Функция вычисления биссектрисы треугольника к стороне а
void find_bisectors(double& a, double& b, double& c, double* bisector_X, double& s) 
{
    // Проверка деления на ноль
    if (b + c == 0 || a + c == 0 || a + b == 0) 
    {
        throw std::string("деление на ноль") ;
    }

    // Проверка на отрицательное значение аргумента корня
    if (b * c * s * (s - a) < 0.0 || a * c * s * (s - b) < 0.0 || a * b * s * (s - c) < 0.0) 
    {
        throw std::string("значение под корнем отрицательное");
    }

    // Вычисление биссектрисы к стороне a
    *bisector_X = 2.0 * sqrt(b * c * s * (s - a)) / (b + c);
}


// Функция для ввода сторон треугольника
void input_sides(double& side, char& side_name)
{
    do 
    {
        std::cout << "Введите длину стороны треугольника "<< side_name << ":";
        std::cin >> side;
        
        // Обработка исключительной ситуации при некорректном вводе
        if (std::cin.fail()) 
        {
            std::cin.clear();  // Сбросить флаги ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очистить буфер ввода
            std::cout << "Ошибка: некорректный ввод!\n";
        }
        else if(side <= 0) 
        {
            std::cout << "Ошибка: длина стороны должна быть положительной!\n";
        }
    } 
    while (side <= 0);  // Повторять ввод, пока не будет введена положительная длина
}

