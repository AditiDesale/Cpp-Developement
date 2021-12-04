//Recursion -- factorial

#include<iostream>
using namespace std;

int FactI(int iNo)
{
	int iFact = 1;
	
	while(iNo != 0)
	{
		iFact = iFact * iNo;;
		iNo--;
	}
	return iFact;
}


int FactR(int iNo)
{
	static int iFact = 1;
	
	if(iNo != 0)
	{
		iFact = iFact * iNo;
		iNo--;
		
		FactR(iNo);
	}
	return iFact;
}
 
 
 int main()
 {
	int i = 0, iRet = 0;
	
	cout << "Enter number : \n";
	cin >> i;
	
	iRet = FactI(i);
	cout << "FactorialI : " << iRet << "\n";
	
	
	iRet = FactR(i);
	cout << "FactorialR : " << iRet << "\n";
	 
	return 0;
 }