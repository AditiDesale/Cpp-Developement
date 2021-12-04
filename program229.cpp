
#include<iostream>
using namespace std;

void DisplayI(int iNo)
{
	int iCnt = 1;
	
	while(iCnt <= iNo)
	{
		cout << "Hello\n";
		iCnt++;
	}
}


void DisplayR(int iNo)
{
	static int iCnt = 1;
	
	if(iCnt <= iNo)
	{
		cout << "Hello\n";
		iCnt++;
		
		DisplayR(iNo);
	}
}
 
 
 int main()
 {
	int i = 0;
	
	printf("Enter number : \n");
	scanf("%d",&i);
	
	DisplayI(i);
	printf("\n");
	DisplayR(i);
	 
	return 0;
 }