//Recursion using C++

#include<iostream>
using namespace std;

void DisplayI()
{
	int iCnt = 1;
	
	while(iCnt <= 4)
	{
		cout << "Hello\n";
		iCnt++;
	}
}


void DisplayR()
{
	static int iCnt = 1;
	
	if(iCnt <= 4)
	{
		cout << "Hello\n";
		iCnt++;
		
		DisplayR();
	}
}
 
 
 int main()
 {
	int i = 0;
	
	DisplayR();
	 
	return 0;
 }