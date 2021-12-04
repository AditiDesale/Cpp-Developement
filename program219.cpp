#include<iostream>
using namespace std;


//Specific function
void Swap(char *p, char *q)    
{
	char temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
}

//Generic function
template <class T>
void SwapX(T *p, T *q)    
{
	T temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
}

int main()
{
	char x = 'A', y = 'Z';
	SwapX(&x,&y); 
	
	cout << "Value of x becomes : " << x << "\n";  
	cout << "Value of y becomes : " << y << "\n";  
	
	cout << "Enter first value : \n";  
	cin >> x;
	
	cout << "Enter second value : \n";  
	cin >> y;
	
	int i = 11, j = 21;
	SwapX(&i,&j);   
	
	cout << "Value of x becomes : " << i << "\n";  
	cout << "Value of y becomes : " << j << "\n";   
	
	return 0;
}