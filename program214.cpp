//Queue

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE;


class Queue
{
	private : 
		PNODE first;
		int size;
		
	public : 
		Queue()
		{
			first = NULL;
			size = 0;
		}
		
		
		void Enqueue(int no)    //InsertLast()
		{
			PNODE newn = new NODE;
			newn -> data = no;
			newn -> next = NULL;
			
			if(size == 0)    //first == NULL
			{
				first = newn;
			}
			else
			{
				PNODE temp = first;
				
				while(temp -> next != NULL)
				{
					temp = temp -> next;
				}
				
				temp -> next = newn;
			}
			
			size++;
		}
		
		
		int Dequeue()   //DeleteFirst()
		{
			int no = 0;
			PNODE temp = first;
			
			if(first == NULL)     //size == 0
			{
				cout << "Queue is empty\n";
				return -1;
			}
			
			if(first -> next == NULL)   //size == 1
			{
				no = first -> data;
				delete first;
				first = NULL;
			}
			else
			{
				no = first -> data;
				first = first -> next;
				delete temp;
			}
			
			size--;
			
			return no;
		}
		
		
		void Display()
		{
			PNODE temp = first;
			 
			for(int i = 1; i <= size; i++ )
			{
				cout << "|" << temp -> data << "| ->";
				temp = temp -> next;
			}
			
			cout << "\n";
		}
		
		
		int Count()
		{
			return size;
		}
};

int main()
{
	Queue obj;
	
	obj.Enqueue(11);
	obj.Enqueue(21);
	obj.Enqueue(51);
	obj.Enqueue(101);
	
	cout << " Elements of queue: \n";
	obj.Display();
	
	int iret = obj.Dequeue();
	cout << "Removed element from queue : " << iret << "\n";
	
	cout << " Elements of queue: \n";
	obj.Display();
	
	iret = obj.Count();
	cout << "Number of elements : " << iret << "\n";
	
	return 0;
}