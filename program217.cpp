#include<iostream>
using namespace std;

void Swap(char *p, char *q)    
{
	char temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
}

int main()
{
	char x = '\0', y = '\0';
	
	cout << "Enter first value : \n";  
	cin >> x;
	
	cout << "Enter second value : \n";  
	cin >> y;
	
	Swap(&x,&y);   
	
	cout << "Value of x becomes : " << x << "\n";  
	cout << "Value of y becomes : " << y << "\n";   
	
	return 0;
}