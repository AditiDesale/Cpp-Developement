//Recursion -- array addition

#include<iostream>
using namespace std;

int SumI(int Arr[], int iSize)
{
	int iSum = 0, i = 0;
	
	for(i = 0; i < iSize; i++)    //using for
	{
		iSum = iSum + Arr[i];
	}
	
	return iSum;
}

int Sum(int Arr[], int iSize)
{
	int iSum = 0, i = 0;
	
	while(i < iSize)           //using while
	{
		iSum = iSum + Arr[i];
		i++;
	}
	return iSum;
}

int SumR(int Arr[], int iSize)
{
	static int iSum = 0, i = 0;
	
	if(i < iSize)                       //using recursion
	{
		iSum = iSum + Arr[i];
		i++;
		
		SumR(Arr,iSize);
	}
	return iSum;
}

int main()
{
	int iLength = 0, i = 0, iRet = 0;
	int *p = NULL;
	
	cout << "Enter number of elements : \n";
	cin >> iLength;
	
	p = new int[iLength];
	
	cout << "Enter elements : \n";
	
	for(i = 0; i < iLength; i++)
	{
		cin >> p[i];
	}
	
	iRet = SumI(p,iLength);
	cout << "AdditionI : " << iRet << "\n";
	
	iRet = Sum(p,iLength);
	cout << "Addition : " << iRet << "\n";
	
	iRet = SumR(p,iLength);
	cout << "AdditionR : " << iRet << "\n";
	
	delete []p;
	
	return 0;
}