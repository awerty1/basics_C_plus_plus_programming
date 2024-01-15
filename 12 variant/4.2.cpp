/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от 1 до 10.
Подсчитать и вывести дополнительным столбцом среднее арифметическое 
каждой четной строки. Найти и вывести наименьший элемент этого столбца.
*/

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iomanip>

const int MIN_VALUE = 1;
const int MAX_VALUE = 10;

int main()
{
    int n, m;
    
    do 
    {
        std::cout << "Введите количество строк: ";
        std::cin >> n;

        if (n <= 0 ) 
        {
            std::cout << "Количество строк должно быть положительным числом." << std::endl;
        }
    } 
    while (n <= 0);
    
    do 
    {
        std::cout << "Введите количество столбцов: ";
        std::cin >> m;

        if (m <= 0) 
        {
            std::cout << "Количество столбцов должно быть положительным числом." << std::endl;
        }
    } 
    while (m <= 0);

    int matrix[n][m];

    // Генерация случайных чисел
    srand(time(0));

    // Заполнение матрицы случайными числами
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
        }
    }

    // Вывод матрицы и подсчет среднего арифметического
    double minElement = MAX_VALUE; // Наименьший элемент столбца
    for (int i = 0; i < n; i++)
    {
        double sum = 0; // Сумма элементов строки
        int count = 0; // Количество элементов строки

        std::cout << "Строка " << i + 1 << ": ";

        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(4) <<matrix[i][j] ;

            if (i % 2 == 1) // Четная строка
            {
                sum += matrix[i][j];
                count++;
            }

            if (j == m - 1 && i % 2 == 1) // Последний элемент четной строки
            {
                double average = sum / count;
                std::cout <<" Среднее арифметическое: " << average;
                minElement = std::min(minElement, average);
            }
        }

        std::cout << std::endl;
    }

    std::cout << "Наименьший элемент средних арифметических: " << minElement << std::endl;

    return 0;
}