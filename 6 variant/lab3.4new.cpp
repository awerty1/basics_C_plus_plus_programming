/*
Задание 4. Сформировать два массива А и В – каждый из n (число n вводится 
с клавиатуры, его значение не больше 20) случайных целых чисел. Элементы 
массива A должны быть в диапазоне от 0 до 20, а элементы массива B – от 0 до 
10. Вывести оба массива, сначала A, потом B. Программа должна сформировать 
массив C, в который необходимо поместить только те элементы массива В, для 
которых есть удвоенные значения в массиве А (предположим, если в массиве В 
есть элемент со значением 7, то значение 7 можно помещать в массив С, если в 
массиве А есть элемент со значением 14). Вывести массив С.
*/

#include <iostream>

using namespace std;

//Функция вывод массива
void show_array(int SIZE, int arrayN[])
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << arrayN[i] << " ";
    }
}

// Заполнение массива случайными числами
void get_rnd(int SIZE, int arrayN[], int from, int to)
{
    for(int i = 0; i < SIZE; i++) 
    {
        arrayN [i] = rand() % from - to;
    } 
}


// Тест на дублирование элементов
void test_double_number(int SIZE, int arrayN[])
{
    bool flag = false;
    for(int i = 0; i < SIZE; i++)
    {
		if (SIZE == 1 || arrayN[SIZE])
        {
            flag = false;
            break;
        }
        if (arrayN[i] != arrayN[i+1])
            flag = false;
        else
        {
            flag = true;
            break;
        }
    }
    
    if (flag)
        cout << "\x1b[31mFAILED\x1b[0m";
    else
        cout << "\x1b[32mPASSED\x1b[0m";
}


int main()
{
    int SIZE;
    cout<<"Введите размер массива:";
    cin>>SIZE;
    int arrayA[SIZE];
    int arrayB[SIZE];
    int arrayC[SIZE] = { 0 };
    if (SIZE <= 0 || SIZE > 20)
    {
        do
        {
          cout<<"\nРазмер массива <= 0 или > 20:"; 
          cout<<"\nВведите размер массива:";
          cin >> SIZE;  
        }while(SIZE <= 0 || SIZE > 20);
    }
    
    srand(time(0));
    
    
    // Заполнение массива A случайными числами 0 до 20 и его вывод
    get_rnd(SIZE, arrayA, 21, 0);
    // Заполнение массива B случайными числами -10 до 10 и его вывод
    get_rnd(SIZE, arrayB, 21, 10);
    
    cout<< "Исходный массив A:\n";
    show_array(SIZE, arrayA);
    
    cout<< "\nИсходный массив B:\n";
    show_array(SIZE, arrayB);
    
    
    
    //поиск удвоенного значения в массиве А
    int count = 0;
	for (int i = 0; i < SIZE; i++) 
	{ 
		for (int j = 0; j < SIZE; j++) 
		{ 
		    // ищем удвоенное значение элемента B в массиве А 
		    // скипаем 0, т.к. 0 = 0 - не удвоенное значение
			if (arrayA[i] == arrayB[j]*2 && arrayA[i] != 0)
			{
				arrayC[count] = arrayB[j]; 
				count++;
			}
		} 
	}
	
	
	//debug version
	if (count == 0)
		cout<< "\nВ массиве \"A\" нет удвоенного произведения элемента из массива B. Массив C пустой!";
	else
	{
	    cout<< "\nИсходный массив С:\n";
        show_array(count, arrayC);
    
    	 //Сортировка массива C
         for(int i = 0; i < count; i++)
         {
             for(int j = 0; j < count-i-1; j++)
             {
                 if(arrayC[j] > arrayC[j+1])
                 {
                     int temp = arrayC[j];
                     arrayC[j] = arrayC[j+1];
                     arrayC[j+1] = temp;
                 }
             }
         }
         
         
         cout<< "\nИсходный массив C после сортировки:\n";
         show_array(count, arrayC);
         
         
        //Удаление дублирующего элемента
    	for (int i = 0; i < SIZE; i++)
    	{
    	    if (arrayC[i] == arrayC[i+1])
    	    {
    	        for(int j = i; j < SIZE-1; j++)
    	        {
    	            arrayC[j] = arrayC[j+1];
    	        }
    	        SIZE--;
    	        i--;
    	    }
    	}
    	
    	 cout<< "\nИсходный массив C после удаления:\n";
    	 show_array(SIZE, arrayC);
    	 
    	 
    	 cout<< "\n\n#####################################"<<endl;
    	 cout<< "################TESTS################"<<endl;
    	 cout<< "#####################################"<<endl;
    	 cout<< "DOUBLE ELEMENTS:"; 
    	 test_double_number(SIZE, arrayC);
    	 
	}
	
    return 0;
}
