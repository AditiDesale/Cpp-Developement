#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT SwapByte(UINT iNo)
{	
	return (iNo & 0x00FFFF00) | (iNo << 24) | (iNo >> 24);
}

int main()
{
	UINT iValue = 0, iRet = 0, i = 0, j = 0;
	
	cout << "Enter number : \n";
	cin >> iValue;
	
	iRet = SwapByte(iValue);

	cout << "Data : " << iRet << "\n";
	
	return 0;
}
/*

     1111 0000 0000 0000 0000 0000 1111
	
	 0000 1111 0000 0000 0000 1111 0000 

*/