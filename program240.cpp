//Tree
//BST
//Inoeder,Preorder,Postorder

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


int CountLeaf(PNODE Head)
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		if((Head -> lchild == NULL) && (Head -> rchild == NULL))
		{
			iCnt++;
			
		}
		
		CountLeaf(Head -> lchild);
		CountLeaf(Head -> rchild);
	}
	return iCnt;
}


int CountParent(PNODE Head)
{
	static int iCnt = 0;
	
	if(Head != NULL)
	{
		if((Head -> lchild != NULL) || (Head -> rchild != NULL))
		{
			iCnt++;
			
		}
		
		CountParent(Head -> lchild);
		CountParent(Head -> rchild);
	}
	return iCnt;
}


void Inorder(PNODE Head)    //LDR
{
	
	if(Head != NULL)
	{		
		Inorder(Head -> lchild);
		cout << Head -> data << "\n";
		Inorder(Head -> rchild);
	}
}


void Preorder(PNODE Head)     //DLR
{
	static int i = 0;
	
	if(Head != NULL)
	{
		cout << Head -> data << "\n";
		Preorder(Head -> lchild);
		Preorder(Head -> rchild);
	}
}


void Postorder(PNODE Head)     //LRD
{
	static int i = 0;
	
	if(Head != NULL)
	{
		Postorder(Head -> lchild);
		Postorder(Head -> rchild);
		cout << Head -> data << "\n";

	}
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
	
	iret = CountLeaf(first);
	cout << "Number of leaf node : " << iret << "\n";
	
	iret = CountParent(first);
	cout << "Number of parent node : " << iret << "\n";
	
	iret = CountEvenData(first);
	cout << "Number of even data in node : " << iret << "\n";
	
	cout << "Inorder\n";
	Inorder(first);
	
	cout << "Preorder\n";
	Preorder(first);
	
	cout << "Postorder\n";
	Postorder(first);
	
	return 0;
}

