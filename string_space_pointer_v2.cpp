#include <iostream>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

void removeSpaces(char *str);
void test_removespaces();


int main() 
{
    //char* str = new char[100];
    
    string str;
    cout << "Введите строку с пробелами: ";
    getline(cin, str);
    
    char* str_ptr = nullptr;
    try {
        str_ptr = new char[str.size()+1];
    }
    catch(bad_alloc& e) {
        cerr << "Ошибка выделения памяти: " 
             << e.what() << endl;
        
        return 1;
    }
    
    strcpy(str_ptr, str.c_str());

    /*
    *******chrono start************
    */
    auto start = chrono::high_resolution_clock::now(); // начало замера времени
    
    removeSpaces(str_ptr);
    test_removespaces();
    
    /*
    *******chrono end************
    */
    auto stop = chrono::high_resolution_clock::now(); // конец замера времени
    
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); // Вычисляем разницу в миллисекундах
    cout << "\nВремя работы программы: " << duration.count() << " секунд." << endl;
    
    delete[] str_ptr;
    
    return 0;
}


void test_removespaces() {
    
    cout << "\033[33m##############\033[0m" << endl;
    cout << "\033[33m#MODULE TESTS#\033[0m" << endl;
    cout << "\033[33m##############\033[0m" << endl;
    
    
    /*Тест на пустую строку*/
    cout << "test 1 \"\"" << endl;
    char test1[] = "";
    removeSpaces(test1);
    assert(strlen(test1) == 0);
    cout << (strlen(test1) == 0 ? 
        "\033[32mPASSED\033[0m\n" : "\033[31mFAILED\033[0m\n") << endl;

    /*Строка содержит только один символ - пробел*/
    cout << "test 2 \" \""<< endl;
    char test2[] = " ";
    removeSpaces(test2);
    assert(strlen(test2) == 0);
    cout << (strlen(test2) == 0 ? 
        "\033[32mPASSED\033[0m\n" : "\033[31mFAILED\033[0m\n") << endl;
    
    /*Строка содержит пробел в середине слова между двумя словами*/
    cout << "test 3 \"Hello world!\""<< endl;
    char test3[] = "Hello world!";
    removeSpaces(test3);
    assert(strcmp(test3, "Helloworld!") == 0);
    cout << (strcmp(test3, "Helloworld!") == 0 ? 
        "\033[32mPASSED\033[0m\n" : "\033[31mFAILED\033[0m\n") << endl;
    
    /*Строка содержит 3 пробела между 4 словами*/
    cout << "test 4 \"This is a test\"" << endl; 
    char test4[] = "This is a test";
    removeSpaces(test4);
    assert(strcmp(test4, "Thisisatest") == 0);
    cout << (strcmp(test4, "Thisisatest") == 0 ? 
        "\033[32mPASSED\033[0m\n" : "\033[31mFAILED\033[0m\n") << endl;
    
    /*Один символ содержит пробел до и после*/
    cout << "test 5 \" A \" " << endl;
    char test5[] = " A ";
    removeSpaces(test5);
    assert(strcmp(test5, "A") == 0);
    cout << (strcmp(test5, "A") == 0 ? 
        "\033[32mPASSED\033[0m\n" : "\033[31mFAILED\033[0m\n") << endl;
    
    /*Строка состоит только из пробелов и табуляций.*/
    cout << "test 6 \" \t \t \" " << endl;
    char test6[] = " \t \t ";
    removeSpaces(test6);
    assert(strcmp(test6, "") == 0);
    cout << (strcmp(test6, "") == 0 ? 
        "\033[32mPASSED\033[0m\n" : "\033[31mFAILED\033[0m\n") << endl;
        
    /*Строка содержит только один символ, но это не пробел*/
    cout << "test 7 \"a\" " << endl;
    char test7[] = "a";
    removeSpaces(test7);
    assert(strcmp(test7, "a") == 0);
    cout << (strcmp(test7, "a") == 0 ? 
        "\033[32mPASSED\033[0m\n" : "\033[31mFAILED\033[0m\n") << endl;
    
    /*Строка содержит несколько пробелов и табуляций перед текстом*/
    cout << "test 8 \" \t\t hello\" " << endl;
    char test8[] = " \t\t hello";
    removeSpaces(test8);
    assert(strcmp(test8, "hello") == 0);
    cout << (strcmp(test8, "hello") == 0 ? 
        "\033[32mPASSED\033[0m\n" : "\033[31mFAILED\033[0m\n") << endl;
        
    /*Строка содержит несколько пробелов и табуляций после текста*/
    cout << "test 9 \"hello \t\t \" " << endl;
    char test9[] = "hello \t\t ";
    removeSpaces(test9);
    assert(strcmp(test9, "hello") == 0);
    cout << (strcmp(test9, "hello") == 0 ? 
        "\033[32mPASSED\033[0m\n" : "\033[31mFAILED\033[0m\n") << endl;
        
}

void removeSpaces(char *str) 
{
    if (!*str) 
    {
        cout << "Строка пуста" << endl;
        return ;
    }
    
    char *p;
    
    size_t i = 0; 
    size_t j = 0;
    
    
    p = str;
    while (*(p+i)) 
    {
        if (*(p+i) != ' ' && *(p+i) != '\t') 
        {
            *(p+j) = *(p+i);
            j++;
        }
        i++;
    }
    
    *(p+j) = '\0';
	
	cout << "Строка без пробелов: " << str << endl;
}

