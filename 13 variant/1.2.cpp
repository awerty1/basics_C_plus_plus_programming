/*
Задание 2. Написать программу вычисления стоимости поездки на 
автомобиле на дачу (туда и обратно). Исходными данными, которые вводятся с 
клавиатуры, являются: расстояние до дачи (в километрах); количество бензина, 
которое потребляет автомобиль на 100 км пробега; цена одного литра бензина.
*/

#include <iostream>
#include <limits>

// Функция для повторного ввода значения, пока не будет получено корректное значение
template<typename T>
T input_with_validation(const std::string& prompt, const std::string& error_prompt, T min_value = std::numeric_limits<T>::min(), T max_value = std::numeric_limits<T>::max()) 
{
    T value;
    bool is_valid = false;

    do 
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value < min_value || value > max_value) 
        {
            std::cout << error_prompt << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else 
        {
            is_valid = true;
        }
    } 
	while (!is_valid);

    return value;
}

int main() 
{
    float distance = input_with_validation<float>("Введите расстояние до дачи (в километрах): ", "Расстояние должно быть положительным числом.");
    float fuel_consumption = input_with_validation<float>("Введите количество бензина, которое потребляет автомобиль на 100 км пробега: ", "Количество бензина должно быть положительным числом.");
    float fuel_price = input_with_validation<float>("Введите цену одного литра бензина: ", "Цена бензина должна быть положительным числом.");
    
    float total_distance = distance * 2; // Расстояние туда и обратно
    float fuel_needed = (fuel_consumption / 100) * total_distance;
    float cost = fuel_needed * fuel_price;

    std::cout << "Стоимость поездки составляет: " << cost << " у.е." << std::endl;

    return 0;
}