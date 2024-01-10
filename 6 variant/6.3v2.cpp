/*
Задание 3. Сформировать два массива – каждый из N (число N вводится с 
клавиатуры, его значение не больше 20) случайных целых чисел. Назовём их A 
и B – элементы массива A должны быть в диапазоне от 0 до 10, а элементы 
массива B – от 0 до 30. Вывести оба массива, сначала A, потом B. Программа 
должна сформировать ещё один массив (допустим, с именем C), в который 
необходимо поместить только те элементы массива А, для которых есть 
утроенные значения в массиве В (предположим, если в массиве А есть элемент 
со значением 5, то значение 5 можно помещать в массив С, если в массиве В есть
элемент со значением 15). Вывести массив С.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_N = 20;
const int MAX_A = 10;
const int MAX_B = 30;

int generateRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void fillArrayWithRandomNumbers(int* array, int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = generateRandomNumber(min, max);
    }
}

void printArray(const int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

bool hasTripleValue(int value, const int* array, int size)
{
    int tripleValue = value * 3;
    
    for (int i = 0; i < size; i++) 
    {
        if (array[i] == tripleValue) 
        {
            return true;
        }
    }
    
    return false;
}

void filterArray(const int* source, int sourceSize, int*& destination, int& destinationSize, const int* filter, int filterSize)
{
    // Избегаем ненужных копирований данных
    // Используем указатели на исходный массив и результат
    destinationSize = 0;
    const int* sourcePtr = source;
    int* destinationPtr = destination;
    for (int i = 0; i < sourceSize; i++)
    {
        if (hasTripleValue(*sourcePtr, filter, filterSize)) 
        {
            *destinationPtr = *sourcePtr;
            destinationPtr++;
            destinationSize++;
        }
        sourcePtr++;
    }
}

int main()
{
    int N;
    std::cout << "Введите число N (не больше " << MAX_N << "): ";
    std::cin >> N;
    
    if (N < 1 || N > MAX_N) 
    {
        std::cout << "Некорректное значение N.\n";
        return 0;
    }
    
    srand(time(0));
    
    int* arrayA = new int[N];
    int* arrayB = new int[N];
    int* arrayC = new int[N];
    int sizeC = 0;
    
    fillArrayWithRandomNumbers(arrayA, N, 0, MAX_A);
    fillArrayWithRandomNumbers(arrayB, N, 0, MAX_B);
    
    std::cout << "Массив A:\n";
    printArray(arrayA, N);
    
    std::cout << "Массив B:\n";
    printArray(arrayB, N);
    
    filterArray(arrayA, N, arrayC, sizeC, arrayB, N);
    
    std::cout << "Массив C:\n";
    printArray(arrayC, sizeC);
    
    delete[] arrayA;
    delete[] arrayB;
    delete[] arrayC;
    
    return 0;
}
