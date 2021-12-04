#include<iostream>
using namespace std;

/*
	op1		op2		&	|	^
	1		0		0	1	1
	0		1		0	1	1
	1		1		1	1	0
	0		0		0	0	0
*/

typedef unsigned int UINT;

int ToggleBit(UINT iNo, int iPos)
{
	int iMask = 0x00000001;
	int iResult = 0;
	
	if((iPos < 1) || (iPos > 32))
	{
		return 0;
	}
	
	iMask = iMask << (iPos - 1);
	
	iResult = iNo ^ iMask;     //toggle logic
	
	return iResult;
}


//position = 5

//iMask = iMask << (pos - 1)
//      = iMask << (5-1)
//      = iMask << 4

//iMask         0 0 0 1 0 0 0 0       5th bit on

// input :      0 1 1 0 0 1 0 0 
//iMask :       0 0 0 1 0 0 0 0    ^
//------------------------------------
//iResult :     0 1 1 1 0 1 0 0

int main()
{
	int iValue = 0, iRet = 0, i = 0;
	
	cout << "Enter number : \n";
	cin >> iValue;
	
	cout << "Enter position : \n";
	cin >> i;
	
	iRet = ToggleBit(iValue,i);
	
	cout << "Updated number : " << iRet << "\n";
	
	return 0;
}