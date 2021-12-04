//Tree
//BST

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE, *PNODE, **PPNODE;


void Insert(PPNODE Head, int no)
{
	PNODE newn = new NODE;
	
	newn -> lchild = NULL;
	newn -> rchild = NULL;
	newn -> data = no;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		PNODE temp = *Head;
		
		while(1)          //Unconditional loop         // while(true)     // for(;;)
		{
			if(temp -> data == no)
			{
				cout << "Duplicate node\n";
				delete newn;
				break;
			}
			else if(temp -> data > no)         
			{
				if(temp -> lchild == NULL)
				{
					temp -> lchild = newn;
					break;
				}
				temp = temp -> lchild;
			}
			else if(temp -> data < no)           
			{
				if(temp -> rchild == NULL)
				{
					temp -> rchild = newn;
					break;
				}
				temp = temp -> rchild;
			}
		}
	}
}


bool Search(PNODE Head, int no)
{	
	if(Head == NULL)   //tree is empty
	{
		return false;
	}
	else    //tree contains atleast one node
	{
		while(Head != NULL)
		{
			if(Head -> data == no)       //found data
			{
				break;
			}
			else if(Head -> data < no)
			{
				Head = Head -> rchild;
			}
			else if(Head -> data > no)
			{
				Head = Head -> lchild;
			}
		}
	}
	if(Head == NULL)          //without using flag
	{
		return false;
	}
	else
	{
		return true;
	}
}


int Count(PNODE Head)
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		iCnt++;
		
		Count(Head -> lchild);
		Count(Head -> rchild);
	}
	return iCnt;
}


int main()
{
	int no = 0, iret = 0;
	bool bret = false;
	
	PNODE first = NULL;
	
	Insert(&first,51);    //if 
	Insert(&first,21);    //else
	Insert(&first,101);   //else
	
	cout << "Enter number to search : \n";
	cin >> no;
	
	bret = Search(first,no);
	if(bret == true)
	{
		cout << "Data found\n";
	}
	else
	{
		cout << "Data not found\n";
	}
	
	iret = Count(first);
	cout << "Number of node : " << iret << "\n";
	
	return 0;
}