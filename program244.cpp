//Queue           //Generic program

#include<iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	struct node *next;
};


template <class T>
class Queue
{
	private : 
		node <T> * first;
		int size;
		
	public : 
		Queue();
		void Enqueue(T no);
		T Dequeue();
		void Display();
		int Count();
};


template <class T>
Queue <T> :: Queue()
{
	first = NULL;
	size = 0;
}


template <class T>
void Queue <T> :: Enqueue(T no)
{
	node <T> * newn = new node <T>;
	newn -> data = no;
	newn -> next = NULL;
			
	if(size == 0)    //first == NULL
	{
		first = newn;
	}
	else
	{
		node <T> * temp = first;
				
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
				
		temp -> next = newn;
	}
			
	size++;
}


template <class T>
T Queue <T> :: Dequeue()
{
	int no = 0;
	node <T> * temp = first;
			
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


template <class T>
void Queue <T> :: Display()
{
	node <T> * temp = first;
			 
	for(int i = 1; i <= size; i++ )
	{
		cout << "|" << temp -> data << "| ->";
		temp = temp -> next;
	}
			
	cout << "\n";
}


template <class T>
int Queue <T> :: Count()
{
	return size;
}



int main()
{
	int iret = 0;
	
	Queue <int> obj;
	
	obj.Enqueue(11);
	obj.Enqueue(21);
	obj.Enqueue(51);
	obj.Enqueue(101);
	
	cout << " Elements of queue: \n";
	obj.Display();
	
	iret = obj.Count();
	cout << "Number of elements : " << iret << "\n";
	
	iret = obj.Dequeue();
	cout << "Removed element from queue : " << iret << "\n";
	
	cout << " Elements of queue: \n";
	obj.Display();
	
	iret = obj.Count();
	cout << "Number of elements : " << iret << "\n";
	
	return 0;
}