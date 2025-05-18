/*
Задание 2. Сформировать массив из N случайных целых чисел в диапазоне от -10 до 10
(число N вводится с клавиатуры, его значение не больше 20) и вывести элементы
этого массива на экран. Вычислить следующие характеристики массива
(вычисление каждой из них оформить как отдельную функцию, параметрами
которой являются количество элементов массива и сам массив):
• логическое значение (true или false) – признак того, что первый
элемент является наименьшим по значению. Если это так, признак
равен true, не так – тогда false;
• среднее арифметическое всех отрицательных элементов массива.
Выполнить следующую перестановку в массиве:
• реверс массива – последний элемент поменять местами с первым,
предпоследний – со вторым и т.д.
Вывести преобразованный таким образом массив.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cassert>

using namespace std;

// Функция для проверки, является ли первый элемент массива наименьшим
bool is_min(const int* arr, const int SIZE)
{
    int min_num = *arr; // Инициализируем минимальный элемент первым элементом массива
    for (int i = 1; i < SIZE; i++)
    {
        if (*(arr+i) < min_num)
        {
            min_num = *(arr+i);  // Обновляем минимальный элемент, если нашли новый
        }
    }

    return *arr == min_num; // Сравниваем первый элемент с минимальным
}

// Функция для вычисления среднего арифметического отрицательных элементов массива
double average_negative(const int* arr, const int SIZE)
{
    int sum = 0.0; // Инициализируем сумму отрицательных элементов
    int count = 0; // Инициализируем количество отрицательных элементов
    
    for (int i = 0; i < SIZE; i++)
    {
        if (*(arr+i) < 0)
        {
            sum += *(arr+i); // Добавляем элемент в сумму
            count++; // Инкрементируем счетчик отрицательных элементов
        }
    }
    
    return count > 0 ? (double)sum / count : 0.0; // Если есть отрицательные элементы, возвращаем среднее арифметическое, иначе - 0
}

// Функция для переворота массива
void reverse(int* arr, const int SIZE)
{
    for (int i = 0; i < SIZE / 2; i++)
    {
        const int index = SIZE - 1 - i; // Вычисляем индекс зеркальной пары для текущего элемента
        const int temp = *(arr+i); // Сохраняем значение текущего элемента во временную переменную
        *(arr+i) = *(arr + index); // Заменяем текущий элемент зеркальным элементом
        *(arr + index) = temp; // Заменяем зеркальный элемент текущим элементом из временной переменной
    }
}

// Функция для вывода элементов массива на экран
void print_array(const int* arr, int SIZE) 
{
    //cout << "Массив:" << endl;
    
    for (int i = 0; i < SIZE; i++) 
    {
        cout << *(arr+i) << " ";
    }
    
    cout << endl;
}

// Функция для заполнения массива случайными числами
void fill_random(int* arr, const int SIZE)
{
    srand(time(nullptr));
    
    for (int i = 0; i < SIZE; i++)
    {
        *(arr+i) = rand() % 21 - 10; // Заполняем элемент случайным числом от -10 до 10
    }
}

// Функция для получения размера массива от пользователя
int get_array_size() 
{
    int SIZE;
    cout << "Введите количество элементов массива (не больше 20): ";
    
    do
    {
        cin >> SIZE;
        if (cin.fail() || SIZE < 1 || SIZE > 20) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Введите целое число от 1 до 20: ";
        } 
        else 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return SIZE;
        }
    } while (true); 
}


//tests
void test_is_min()
{
    {
        int arr[] = {-1, 2, 3};
        assert(is_min(arr, 3) == true);
    }
        
    {
        int arr[] = {1, -2, 3};
        assert(is_min(arr, 3) == false);
    }
        
    {
        int arr[] = {1, 1, 1};
        assert(is_min(arr, 3) == true);
    }
}


void test_average_negative()
{
    
    {
        int arr[] = {-2, 2, -3};
        assert((average_negative(arr, 3)) == -2.5);
    }
    
    {
        int arr[] = {1, 2, 3};
        assert(average_negative(arr, 3) == 0.0);
    }
    
    {
    int arr[] = {0, 0, 0};
    assert(average_negative(arr, 3) == 0.0);
    }
}


void test_reverse()
{
    {
        int arr[] = {1, 2, 3};
        int expected[] = {3, 2, 1};
        
        reverse(arr, 3);
        
        for (int i = 0; i < 3; i++)
        {
            assert(arr[i] == expected[i]);
        }
    }
        
    {
        int arr[] = {1, 2, 3, 4};
        int expected[] = {4, 3, 2, 1};
        
        reverse(arr, 4);
        
        for (int i = 0; i < 4; i++)
        {
            assert(arr[i] == expected[i]);
        }
    }
        
    {
        int arr[] = {1};
        int expected[] = {1};
        
        reverse(arr, 1);
        
        for (int i = 0; i < 1; i++)
        {
            assert(arr[i] == expected[i]);
        }
    }
}


int main()
{
    srand(time(nullptr));
    
    int SIZE = get_array_size();
    int* arr = new int[SIZE];
    
    // Заполнение массива случайными числами.
    fill_random(arr, SIZE);
    
    cout << "Сгенерированный массив:" << endl;
    print_array(arr, SIZE);
    
    
    const bool is_min_value = is_min(arr, SIZE);
    cout << "Первый элемент является наименьшим: " << boolalpha 
         << is_min_value << endl;
         
    const double avg_neg_value = average_negative(arr, SIZE);
    cout << "Среднее арифметическое всех отрицательных элементов: " 
         << avg_neg_value << endl;
    
    // Переворачиваем массив
    reverse(arr, SIZE);
    
    cout << "Перевернутый массив:" << endl;
    print_array(arr, SIZE);
    
    //Запускаем тесты
    test_is_min();
    test_average_negative();
    test_reverse();
    
    
    delete [] arr;
    
    cout << "All tests passed!\n";
    
    return 0;
}

