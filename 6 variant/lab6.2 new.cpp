/*
Задание 2. Сформировать массив из N случайных целых чисел в диапазоне 
от -10 до 10 (число N вводится с клавиатуры, его значение не больше 20) и 
вывести элементы этого массива на экран. Вычислить следующие 
характеристики массива (вычисление каждой из них оформить как отдельную 
функцию, параметрами которой являются количество элементов массива и сам 
массив):
• количество элементов массива, равных нулю;
• логическое значение (true или false) – признак того, что элементы 
массива упорядочены по неубыванию. Если упорядоченность 
нарушена, этот признак равен false.
Выполнить следующую перестановку в массиве:
• поменять местами максимальный и минимальный элементы (если 
таких элементов несколько, взять первые из них).
Вывести преобразованный таким образом массив.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

// Функция для генерации массива из N случайных целых чисел в диапазоне от -10 до 10
void generateArray(int N, int arr[]) 
{
    std::srand(std::time(nullptr)); // Задаем начальное значение генератора случайных чисел

    for (int i = 0; i < N; i++) 
    {
        arr[i] = std::rand() % 21 - 10; // Генерируем случайное число от -10 до 10
    }
}

// Функция для вывода элементов массива на экран
void printArray(int N, int arr[]) 
{
    for (int i = 0; i < N; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Функция для подсчета количества элементов массива, равных нулю
int countZeros(int N, int arr[]) 
{
    int count = 0;
    for (int i = 0; i < N; i++) 
    {
        if (arr[i] == 0) 
        {
            count++;
        }
    }
    return count;
}

// Функция для проверки упорядоченности элементов массива по неубыванию
bool isSorted(int N, int arr[]) 
{
    for (int i = 1; i < N; i++) 
    {
        if (arr[i] < arr[i-1]) 
        {
            return false;
        }
    }
    return true;
}

// Функция для нахождения индекса минимального элемента массива
int findMinIndex(int N, int arr[]) 
{
    int minIndex = 0;
    for (int i = 1; i < N; i++) 
    {
        if (arr[i] < arr[minIndex]) 
        {
            minIndex = i;
        }
    }
    return minIndex;
}

// Функция для нахождения индекса максимального элемента массива
int findMaxIndex(int N, int arr[]) 
{
    int maxIndex = 0;
    for (int i = 1; i < N; i++) 
    {
        if (arr[i] > arr[maxIndex]) 
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Функция для выполнения перестановки: замена местами максимального и минимального элементов
void swapMinMax(int N, int arr[]) 
{
    int minIndex = findMinIndex(N, arr);
    int maxIndex = findMaxIndex(N, arr);
    int temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;
}

int main() 
{
    int N;
    std::cout << "Введите количество элементов массива (не более 20): ";
    std::cin >> N;

    int arr[20];
    generateArray(N, arr);

    std::cout << "Сгенерированный массив: ";
    printArray(N, arr);

    int zeroCount = countZeros(N, arr);
    std::cout << "Количество элементов массива, равных нулю: " << zeroCount << std::endl;

    bool isAscending = isSorted(N, arr);
    std::cout << "Массив упорядочен по неубыванию? " << (isAscending ? "Да" : "Нет") << std::endl;

    swapMinMax(N, arr);

    std::cout << "Преобразованный массив: ";
    printArray(N, arr);

    return 0;
}