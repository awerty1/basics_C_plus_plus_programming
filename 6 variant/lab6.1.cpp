/*
Задание 1. Написать функцию, которая вычисляет сопротивление цепи,
состоящей из двух резисторов. С клавиатуры вводятся сопротивления и тип
соединения (последовательное или параллельное). Если неверно указан тип
соединения, то выводится ошибка.
*/
#include <iostream>

using namespace std;

// Функция для вычисления сопротивления при последовательном соединении
float calcSeries(float res1, float res2) 
{
	return res1 + res2;
}

// Функция для вычисления сопротивления при параллельном соединении
float calcParallel(float res1, float res2) 
{
	return (res1 * res2) / (res1 + res2);
}

int main() 
{
	float res1, res2, resTotal;
	int type;

	cout << "Введите сопротивление первого резистора: ";
	cin >> res1;

	cout << "Введите сопротивление второго резистора: ";
	cin >> res2;

	cout << "Введите тип соединения (0 - последовательное, 1 - параллельное): ";
	cin >> type;

	if (type == 0) 
	{
		resTotal = calcSeries(res1, res2);
	} 
	else if (type == 1) 
	{
		resTotal = calcParallel(res1, res2);
	} 
	else 
	{
		cout << "Ошибка: неверный тип соединения." << endl;
		return 1;
	}

	cout << "Сопротивление цепи: " << resTotal << endl;
	
	return 0;
}


/*
Задание 1. Написать функцию, которая вычисляет сопротивление цепи,
состоящей из двух резисторов. С клавиатуры вводятся сопротивления и тип
соединения (последовательное или параллельное). Если неверно указан тип
соединения, то выводится ошибка.

#include <iostream>
#include <limits>
#include <cassert>

using namespace std;

// Функция для вычисления сопротивления при последовательном соединении
float calc_series(float* res1, float* res2) 
{
	return *res1 + *res2;
}

// Функция для вычисления сопротивления при параллельном соединении
float calc_parallel(float* res1, float* res2) 
{
    if(*res1 == 0 || *res2 == 0) // проверка на то, что значения резисторов не равны нулю
    {
        throw "Ошибка: неверное значение резистора";
    }
    
	return (*res1 * *res2) / (*res1 + *res2);
}
// Тест для вычисления сопротивления между двумя резисторами в последовательном соединении.
void test_calc_series() 
{
    float res1 = 10.0;
    float res2 = 20.0;
    float expected_result = 30.0;
    float result = calc_series(&res1, &res2);
    assert(result == expected_result);
}
//Тест для вычисления сопротивления между двумя резисторами в параллельном соединении.
void test_calc_parallel() 
{
    float res1 = 15.0;
    float res2 = 25.0;
    float expected_result = 9.375;
    float result = calc_parallel(&res1, &res2);
    assert(result == expected_result);
}
//Тест для проверки, что функция calc_parallel выбрасывает исключение при нулевом значении резистора.
void test_calc_parallel_exception() 
{
    float res1 = 0.0;
    float res2 = 20.0;
    bool exception_thrown = false;
    try 
    {
        calc_parallel(&res1, &res2);
    } 
    catch (const char* error_msg) 
    {
        exception_thrown = true;
    }
    assert(exception_thrown);
}


int main() 
{
	float* res1 = new float; 
	float* res2 = new float; 
	float res_total;
	int type;
	bool input_correct = false; // флаг, указывающий, что значения, введенные пользователем, верны
	
	
    while(!input_correct) // цикл продолжается до тех пор, пока не будут введены верные значения
    { 
        try 
        {
        	cout << "Введите сопротивление первого резистора: ";
        	cin >> *res1;
            
            if (cin.fail()) // проверка на корректность введенного значения 
            { 
                throw "Ошибка: введено неверное значение";
            }

        	cout << "Введите сопротивление второго резистора: ";
        	cin >> *res2;
        	if (cin.fail()) // проверка на корректность введенного значения
        	{
        	    throw "Ошибка: введено неверное значение";
            }

        	cout << "Введите тип соединения (0 - последовательное, 1 - параллельное): ";
        	cin >> type;
        	
        	if (cin.fail() || (type != 0 && type != 1)) // проверка на корректность введенного значения
        	{ 
                throw "Ошибка: неверный тип соединения.";
            }
            
            input_correct = true; // если все значения верны, устанавливаем флаг в true
                
        } 
        catch (const char* error_msg) // выводим сообщение об ошибке и запрашиваем ввод заново
        { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << error_msg << endl;
        }
    }
    
    try 
    {
        
    	(type == 0) ? res_total = calc_series(res1, res2) : res_total = calc_parallel(res1, res2);
    	
    }
    catch (const char* error_msg) // выводим сообщение об ошибке в случае, если функция calcparallel выдала ошибку
    { 
        cout << error_msg << endl;
        delete res1;
        delete res2;
        return 1;
    }
        
        
	cout << "Сопротивление цепи: " << res_total << endl;
	
	test_calc_series();
	test_calc_parallel();
    test_calc_parallel_exception();
    cout << "ALL TESTS PASSED" << endl;
    
	delete res1;
    delete res2;
    
    
     
	return 0;
}
*/
