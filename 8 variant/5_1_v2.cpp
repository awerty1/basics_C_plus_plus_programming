/*
Задание 1. Вводится строка произвольного текста. Вывести на экран все
заглавные буквы. Если пробелов нет в строке, вывести -1.
*/

#include <iostream>
#include <string>

int main() 
{
  std::string input;
  std::cout << "Введите строку: ";
  std::getline(std::cin, input);
  
  std::string upper_case_letters = ""; 
  bool found_uppercase = false;
  bool found_space = false;
  
  for (char c : input) 
  {
      if (std::isupper(c)) 
      {
          upper_case_letters += c;
          found_uppercase = true;
          
      }
      
      if (std::isspace(c))
      {
        found_space = true;
      }
      
  }

  if ((!found_uppercase || found_uppercase) && !found_space) 
  {
    std::cout << "-1";
  }
  else
  {
      std::cout << "Заглавные буквы:";
      std::cout << upper_case_letters;
  }

  return 0;
}