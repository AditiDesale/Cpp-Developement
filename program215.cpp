#include<iostream>
using namespace std;

void Swap(int *p, int *q)    //Swap(11,21)
{
	int temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
}

int main()
{
	int x = 0, y = 0;
	
	cout << "Enter first number : \n";   //11
	cin >> x;
	
	cout << "Enter second number : \n";   //21
	cin >> y;
	
	Swap(&x,&y);    //Swap(100,200)
	
	cout << "Value of x becomes : " << x << "\n";   //21
	cout << "Value of y becomes : " << y << "\n";   //11
	
	return 0;
}