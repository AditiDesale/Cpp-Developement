//Doubly Linear LinkedList using C++         //Generic program

#include<iostream>
using namespace std;


template <typename T>
struct node
{
    T data;
    struct node *next;
	struct node *prev;
};


template <class T>
class DoublyLL
{
	private:
		node <T> * first;
		int size;
    
	public:
		DoublyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T ,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();
		int Count();
};


template <class T>
DoublyLL <T> :: DoublyLL()
    {
        first = NULL;
        size = 0;
    }
    
	
	template <class T>
    void DoublyLL <T> :: InsertFirst(T no)
    {
        node <T> * newn = new node <T>; 
        
        newn -> data = no;
        newn -> next = NULL;
		newn -> prev = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            first -> prev = newn;
			newn -> next = first;
			first = newn;
        }
        size++;
    }
    
	
	template <class T>
    void DoublyLL <T> :: InsertLast(T no)
    {
        node <T> * newn = new node <T>;  
        
        newn -> data = no;
        newn -> next = NULL;
		newn -> prev = NULL;
		        
        if(first == NULL)
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
			newn -> prev = temp;
        }
        size++;
    }
    
	
	template <class T>
    void DoublyLL <T> :: InsertAtPos(T no, int ipos)
    {
		if((first == NULL) || (ipos < 0) || (ipos > size+1))
		{
			return;
		}
		
		if(ipos == 1)
		{
			InsertFirst(no);
		}
		else if(ipos == size+1)
		{
			InsertLast(no);
		}
		else
		{
			node <T> * newn = new node <T>;
			node <T> * temp = first;
			
			if(newn == NULL)
			{
				return;
			}
			
			newn -> data = no;
			newn -> next = NULL;
			newn -> prev = NULL;
			
			for(int i = 1; i < ipos-1; i++)
			{
				temp = temp -> next;
			}
			
			newn -> next = temp -> next;
			temp -> next -> prev = newn;
			newn -> prev = temp;
			temp -> next = newn;
		}
		
		size++;
	}
    
	
	template <class T>
    void DoublyLL <T> :: DeleteFirst()
    {
        node <T> * temp = first;
        
        if(first == NULL)
		{
			return;
		}
		
		if(first != NULL)
        {
            first = first -> next;
			first -> prev = NULL;
            delete temp;
            
            size--;
        }
    }
    
	
	template <class T>
    void DoublyLL <T> :: DeleteLast()
    {
        node <T> * temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first -> next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            
			temp -> prev -> next = NULL;
            delete temp;
            size--;
        }
    }
	
	
	template <class T>
    void DoublyLL <T> :: DeleteAtPos(int ipos)
    {
		if((first == NULL) || (ipos < 1) || (ipos > size))
		{
			return;
		}
		
		if(ipos == 1)
		{
			DeleteFirst();
		}
		else if(ipos == size)
		{
			DeleteLast();
		}
		else
		{
			node <T> * temp = first;
			
			for(int i = 1; i < ipos-1; i++)
			{
				temp = temp -> next;
			}
			
			temp -> next = temp -> next -> next;
			delete temp -> next -> prev;
			temp -> next -> prev = temp;
		}
		size--;
	}
    
	
	template <class T>
    void DoublyLL <T> :: Display()
    {
        node <T> * temp = first;
        
        while(temp != NULL)
        {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "\n";
    }
    
	
	template <class T>
    int DoublyLL <T> :: Count()
    {
        return size;
    }


int main()
{
	int iret = 0;
	
	DoublyLL <char> cobj;                  //char
	
    
    cobj.InsertFirst('C');
    cobj.InsertFirst('B');
    cobj.InsertFirst('A');
    
    cobj.InsertLast('D');
    cobj.InsertLast('E');
	
	cobj.InsertAtPos('X',4);
    
    cobj.Display();
    
    iret = cobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
	
	
	cobj.DeleteAtPos(4);
	cobj.DeleteFirst();
	cobj.DeleteLast();
	
	cobj.Display();
	
	iret = cobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
	
	/////////////////////////////////////////////////////////
	
	DoublyLL <int> iobj;                  //int
	
    
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    
    iobj.InsertLast(101);
    iobj.InsertLast(111);
	
	iobj.InsertAtPos(88,4);
    
    iobj.Display();
    
    iret = iobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
	
	
	iobj.DeleteAtPos(4);
	iobj.DeleteFirst();
	iobj.DeleteLast();
	
	iobj.Display();
	
	iret = iobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    
    return 0;
}
