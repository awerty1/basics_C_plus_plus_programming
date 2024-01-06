/*
Задание 1. Вычислить период колебания маятника длины l. Длина вводится 
с клавиатуры.
*/

#include <iostream>
#include <cmath>

int main() 
{
  const double pi = 3.14159265358979323846;
  double l, g, T;

  try 
  {
    // Ввод длины маятника
    std::cout << "Введите длину маятника: ";
    std::cin >> l;

    // Проверка на отрицательное значение длины маятника
    if (l <= 0) 
    {
      throw std::runtime_error("Длина маятника должна быть положительным числом.");
    }

    // Ввод ускорения свободного падения
    std::cout << "Введите ускорение свободного падения: ";
    std::cin >> g;

    // Проверка на отрицательное значение ускорения свободного падения
    if (g <= 0) 
    {
      throw std::runtime_error("Ускорение свободного падения должно быть положительным числом.");
    }

    // Вычисление периода колебания маятника
    T = 2 * pi * sqrt(l / g);

    // Вывод результата
    std::cout << "Период колебания маятника: " << T << std::endl;
  }
  catch (std::exception &e) 
  {
    std::cout << "Ошибка: " << e.what() << std::endl;
  }

  return 0;
}