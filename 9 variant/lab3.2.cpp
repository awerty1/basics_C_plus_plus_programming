/*
Задание 2. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Заменить все отрицательные элементы 
с номерами от n1 до n2 на среднее арифметическое этого массива. n1, n2 вводятся 
с клавиатуры. Сделать проверку на корректность ввода n, n1 и n2.
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Введите число n (не больше 20): ";
    cin >> n;

    while (n > 20 || n < 1)
    {
        cout << "Некорректное значение! Введите число n (не больше 20): ";
        cin >> n;
    }

    int arr[n];
    cout << "Введите элементы массива:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int n1, n2;
    cout << "Введите значения n1 и n2: ";
    cin >> n1 >> n2;

    while (n1 > n2 || n1 < 1 || n1 > n || n2 < 1 || n2 > n)
    {
        cout << "Некорректные значения! Введите значения n1 и n2: ";
        cin >> n1 >> n2;
    }

    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i >= n1 - 1 && i <= n2 - 1 && arr[i] < 0)
        {
            continue;
        }
        sum += arr[i];
        count++;
    }

    float average = (float)sum / count;

    for (int i = n1 - 1; i <= n2 - 1; i++)
    {
        if (arr[i] < 0)
        {
            arr[i] = average;
        }
    }

    cout << "Измененный массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

