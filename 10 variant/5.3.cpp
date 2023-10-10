/*
Задание 3. Вводятся две строки произвольного текста. Найти количество
совпавших символов, находящихся на одних и тех же позициях в разных
строках.
*/

#include <iostream>
#include <string>

int main() 
{
    try 
    {
        std::string str1, str2;
        int count = 0;
        
        do 
        {
            std::cout << "Введите первую строку: ";
            std::getline(std::cin, str1);
            std::cout << "Введите вторую строку: ";
            std::getline(std::cin, str2);
            
            if (std::cin.fail()) 
            {
                throw std::runtime_error("Ошибка ввода. Проверьте ваши входные данные.");
            }
            
            count = 0;
            for (size_t i = 0; i < std::min(str1.length(), str2.length()); i++) 
            {
                if (str1[i] == str2[i]) 
                {
                    count++;
                }
            }
            
            if (count == 0) 
            {
                std::cout << "Нет совпадающих символов на одинаковых позициях. Попробуйте еще раз.\n";
            }
        } while (count == 0);
        
        std::cout << "Количество совпадающих символов: " << count << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}