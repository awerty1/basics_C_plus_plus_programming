/*
Задание 1. Вычислить расстояние между двумя точками с координатами (х1, 
у1) и (х2, у2). Координаты точек вводятся с клавиатуры.
*/


#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	setlocale(LC_ALL,"Russian");
	float x1,y1,x2,y2,l,stex,stey;
	cout<< "Введите координаты первой точки \n";
	cin>>x1>>y1;
	cout<< "Введите координаты второй точки \n";
	cin>>x2>>y2;
	stex= pow ((x2-x1),2);
	stey= pow ((y2-y1),2);
	l=sqrt(stex+stey);
	cout<<"Расстояние между двумя точками = "<<l;
}