#include<iostream>
using namespace std;

int ToggleBit(int iNo, int iPos1, int iPos2)
{
	int iMask1 = 0x00000001, iMask2 = 0x00000001;
	int iMask = 0;
	int iResult = 0;
	
	if( ((iPos1 < 1) || (iPos1 > 32)) && ((iPos1 < 1) || (iPos1 > 32)) )
	{
		return 0;
	}
	
	iMask1 = iMask1 << (iPos1 - 1);
	iMask2 = iMask2 << (iPos2 - 1);
	
	iMask = iMask1 | iMask2;
	
	iResult = iNo ^ iMask;
	
	return iResult;
}

int main()
{
	int iValue = 0, iRet = 0, i = 0, j = 0;
	
	cout << "Enter number : \n";
	cin >> iValue;
	
	cout << "Enter first position : \n";
	cin >> i;
	
	cout << "Enter second position : \n";
	cin >> j;
	
	iRet = ToggleBit(iValue,i,j);
	
	cout << "Updated number : " << iRet << "\n";
	
	return 0;
}



//position = 5  7 

//iMask = iMask << (pos - 1)
//      = iMask << (5-1)
//      = iMask << 4

//iMask         0 1 0 1 0 0 0 0       5th 7th bit on

// input :      0 1 1 0 0 1 0 0 
//iMask :       0 1 0 1 0 0 0 0    ^
//------------------------------------
//iResult :     0 0 1 1 0 1 0 0