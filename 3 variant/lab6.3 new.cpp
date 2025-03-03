/*
 * Задание 3. Сформировать два массива – каждый из N (число N вводится с 
 * клавиатуры, его значение не больше 20) случайных целых чисел. Назовём их A 
 * и B – элементы массива A должны быть в диапазоне от 0 до 10, а элементы 
 * массива B – от 0 до 20. Вывести оба массива, сначала A, потом B. Программа 
 * должна сформировать ещё один массив (допустим, с именем C), в который 
 * необходимо поместить только те элементы массива А, для которых есть 
 * удвоенные значения в массиве В (предположим, если в массиве А есть элемент 
 * со значением 5, то значение 5 можно помещать в массив С, если в массиве В есть
 * элемент со значением 10). Вывести массив С.
 */
 
#include <iostream>
#include <cstdlib>
#include <ctime>

void generateArray(int N, int array[], int min, int max) 
{
    std::srand(std::time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < N; ++i) 
    {
        array[i] = std::rand() % (max - min + 1) + min; // Генерация случайного числа в указанном диапазоне
    }
}

void printArray(int N, int array[]) 
{
    for (int i = 0; i < N; ++i) 
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void findDoubledValues(int N, const int arrayA[], const int arrayB[], int arrayC[], int& arrayCSize) 
{
    arrayCSize = 0; // Изначально размер массива C равен 0
    for (int i = 0; i < N; ++i) 
    {
        int doubledValue = arrayA[i] * 2;
        for (int j = 0; j < N; ++j) 
        {
            if (arrayB[j] == doubledValue) 
            {
                arrayC[arrayCSize] = arrayA[i];
                ++arrayCSize;
                break; // Найдено удвоенное значение, переходим к следующему элементу массива A
            }
        }
    }
}

int main() 
{
    int N;
    std::cout << "Введите количество элементов массивов (не более 20): ";
    std::cin >> N;

    if (N > 20) 
    {
        std::cout << "Ошибка! Количество элементов превышает 20." << std::endl;
        return 0;
    }

    int arrayA[20];
    int arrayB[20];
    int arrayC[20];
    int arrayCSize;

    generateArray(N, arrayA, 0, 10);
    generateArray(N, arrayB, 0, 20);

    std::cout << "Массив A: ";
    printArray(N, arrayA);

    std::cout << "Массив B: ";
    printArray(N, arrayB);

    findDoubledValues(N, arrayA, arrayB, arrayC, arrayCSize);

    std::cout << "Массив C: ";
    printArray(arrayCSize, arrayC);

    return 0;
}