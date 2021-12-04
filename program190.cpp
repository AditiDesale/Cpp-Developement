#include<iostream>
using namespace std;

int CountBit(int iNo)
{
	int iCnt = 0,i = 0, iResult = 0;
	int iMask = 0x00000001;
	
	for(i = 1; i < 32; i++)
	{
		iResult = iNo & iMask;
		
		if(iResult == iMask)
		{
			iCnt++;
		}
		iMask = iMask << 1;
	}
	return iCnt;
}

int main()
{
	int iValue = 0, iRet = 0;
	
	cout << "Enter number : \n";
	cin >> iValue;
	
	iRet = CountBit(iValue);
	
	cout << "Number of ON bits : " << iRet << "\n";
	
	return 0;
}