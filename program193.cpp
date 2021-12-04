#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT ToggleNibble(UINT iNo)
{
	UINT iMask = 0xF000000F;      //fist and last nibble toggle
	// 1111 0000 0000 0000 0000 0000 0000 1111
	//	 F   0     0    0    0    0    0    F
	UINT iResult = 0;
	
	iResult = iNo ^ iMask;   
	
	return iResult;
}

int main()
{
	UINT iValue = 0, iRet = 0;
	
	cout << "Enter number : \n";
	cin >> iValue;
	
	iRet = ToggleNibble(iValue);
	
	cout << "Updated number : " << iRet << "\n";
	
	return 0;
}


// 11

// 0000 0000 0000 0000 0000 0000 0000 1011
// 1111 0000 0000 0000 0000 0000 0000 0100  -> toggled nibble