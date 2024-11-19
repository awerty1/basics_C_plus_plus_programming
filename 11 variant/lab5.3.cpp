/*
Задание 3. Выяснить, является ли данное слово палиндромом (так
называются слова, читающиеся одинаково слева направо и справа налево,
например, потоп, наган).
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    char word[100];
    int n, i;
    bool flag = true;
    
    cout << "Введите слово: ";
    cin >> word;
    
    n = strlen(word);
    for (i = 0; i < n/2; i++) 
    {
        if (word[i] != word[n-i-1]) 
        {
            flag = false;
            break;
        }
    }
    
    if (flag)
        cout << "Слово является палиндромом";
    else
        cout << "Слово не является палиндромом";
    
    return 0;
}