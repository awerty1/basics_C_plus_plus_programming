/*
Задание 1. Написать программу, которая вычисляет сумму всех чётных 
двузначных чисел.
*/

#include <iostream>

int main() 
{
   int sum = 0;

   for (int i = 10; i <= 99; i += 2) 
   {
       sum += i;
   }

   std::cout << "Сумма всех чётных двузначных чисел: " << sum << std::endl;

   return 0;
}