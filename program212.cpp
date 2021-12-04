//Doubly Circular LinkedList using C++

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE, *PNODE;


class DoublyCL
{
	private : 
		PNODE first;
		PNODE last;
		int size;
		
	public : 
		DoublyCL()
		{
			first = NULL;
			last = NULL;
			size = 0;
		}
		
		void Display();
		int Count();
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no,int ipos);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int ipos);
		
};

//Return_value  Class_name :: Function_name(parameters)

void DoublyCL :: InsertFirst(int no)
{
	PNODE newn = new NODE;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn -> next = first;
		first -> prev = newn;
		first = newn;
	}
	
	last -> next = first;
	first -> prev = last;
	
	size++;
}


void DoublyCL :: InsertLast(int no)
{
	PNODE newn = new NODE;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last -> next = newn;
		newn -> prev = last;
		last = newn;
	}
	
	last -> next = first;
	first -> prev = last;
	
	size++;
}


void DoublyCL :: Display()
{
	PNODE temp = first;
	
	for(int i = 1; i <= size; i++)
	{
		cout << "|" << temp -> data << "| ->";
		temp = temp -> next;
	}
	cout << "\n";
}


int DoublyCL :: Count()
{
	PNODE temp = first;
	int icnt = 0;
	
	for(int i = 1; i <= size; i++)
	{
		icnt++;
		temp = temp -> next;
	}
	cout << "\n";
}


void DoublyCL :: DeleteFirst()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		first = first -> next;
		delete last -> next;
		
		first -> prev = last;
		last -> next = first;
		
	}
	
	size--;
}


void DoublyCL :: DeleteLast()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		last = last -> prev;
		delete last -> next;
		
		first -> prev = last;
		last -> next = first;
	}
	
	size--;
}


void DoublyCL :: InsertAtPos(int no,int ipos)
{
	if((ipos < 1) || (ipos > size+1))
	{
		return;
	}
	else if(ipos == size+1)
	{
		InsertFirst(no);
	}
	else
	{
		PNODE newn = new NODE;
		
		newn -> data = no;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		PNODE temp = first;
		
		for(int i = 1; i < ipos-1; i++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		newn -> next -> prev = newn;
		temp -> next = newn;
		newn -> prev = temp;
		
		size++;
	}
}


void DoublyCL :: DeleteAtPos(int ipos)
{
	if((ipos < 1) || (ipos > size))
	{
		return;
	}
	else if(ipos == 1)
	{
		DeleteLast();
	}
	else
	{
		PNODE temp = first;
		
		for(int i = 1; i < size; i++)
		{
			temp = temp -> next;
		}
		
		temp -> next = temp -> next -> next;
		delete temp -> next -> prev;
		temp -> next -> prev = temp;
		
		size--; 
	}
}


int main()
{
	DoublyCL obj;
	
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	
	obj.InsertLast(51);
	obj.InsertLast(101);
	
	obj.InsertAtPos(75,3);
	
	obj.Display();
	
	int iret = obj.Count();
	cout << "Number of elements : " << iret << "\n";
	
	obj.DeleteAtPos(3);
	obj.DeleteFirst();
	obj.DeleteLast();
	
	obj.Display();

	int iret = obj.Count();
	cout << "Number of elements : " << iret << "\n";
	
	return 0;
}