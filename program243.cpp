//Stack               //Generic program

#include<iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	struct node *next;
};


template <class T>
class Stack
{
	private : 
		node <T> * first;
		int size;
		
	public : 
		Stack();
		void push(T no);
		T pop();
		void Display();
		int Count();
};


template <class T>
Stack <T> :: Stack()
{
	first = NULL;
	size = 0;
}


template <class T>
void Stack <T> :: push(T no)
{
	node <T> * newn = new node <T>;
			
	newn -> data = no;
	newn -> next = NULL;
			
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn -> next = first;
		first = newn;
	}
		
	size++;
}


template <class T>
T Stack <T> :: pop()
{
	int no = 0;
	
	node <T> * temp = first;
			
	if(first == NULL)     //size == 0
	{
		cout << "Stack is empty\n";
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


template<class T>
void Stack <T> :: Display()
{
	node <T> * temp = first;
			
	while(temp != NULL)
	{
		cout << "|" << temp -> data << "|" << "\n";
		temp = temp -> next;
	}
}


template <class T>
int Stack <T> :: Count()
{
	return size;
}



int main()
{
	int iret = 0;
	Stack <int> obj;
	
	obj.push(11);
	obj.push(21);
	obj.push(51);
	obj.push(101);
	
	cout << " Elements of stack: \n";
	obj.Display();
	
	iret = obj.Count();
	cout << "Number of elements : " << iret << "\n";
	
	iret = obj.pop();
	cout << "Popped element : " << iret << "\n";
	
	cout << " Elements of stack: \n";
	obj.Display();
	
	iret = obj.Count();
	cout << "Number of elements : " << iret << "\n";
	
	return 0;
}