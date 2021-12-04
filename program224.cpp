//Doubly Linear LinkedList using C++         //specific program

#include<iostream>
using namespace std;


typedef struct node
{
    int data;
    struct node *next;
	struct node *prev;
}NODE, *PNODE, **PPNODE;


class DoublyLL
{
	private:
		PNODE first;
		int size;
    
	public:
		DoublyLL();
		void InsertFirst(int);
		void InsertLast(int);
		void InsertAtPos(int ,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();
		int Count();
};


DoublyLL :: DoublyLL()
    {
        first = NULL;
        size = 0;
    }
    
	
    void DoublyLL :: InsertFirst(int no)
    {
        PNODE newn = new NODE; 
        
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
    
	
    void DoublyLL :: InsertLast(int no)
    {
        PNODE newn = new NODE;  
        
        newn -> data = no;
        newn -> next = NULL;
		newn -> prev = NULL;
		        
        if(first == NULL)
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
			newn -> prev = temp;
        }
        size++;
    }
    
	
    void DoublyLL :: InsertAtPos(int no, int ipos)
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
			PNODE newn = new NODE;
			PNODE temp = first;
			
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
    
	
    void DoublyLL :: DeleteFirst()
    {
        PNODE temp = first;
        
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
    
	
    void DoublyLL :: DeleteLast()
    {
        PNODE temp = first;
        
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
	
	
    void DoublyLL :: DeleteAtPos(int ipos)
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
			PNODE temp = first;
			
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
    
	
    void DoublyLL :: Display()
    {
        PNODE temp = first;
        
        while(temp != NULL)
        {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "\n";
    }
    
	
    int DoublyLL :: Count()
    {
        return size;
    }


int main()
{
	DoublyLL obj;
	
    int iret = 0;
    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(101);
    obj.InsertLast(111);
    
	obj.InsertAtPos(88,4);
	
    obj.Display();
    
    iret = obj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
	
	
	obj.DeleteAtPos(4);
	obj.DeleteFirst();
	obj.DeleteLast();
	
	obj.Display();
    
    iret = obj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    
    return 0;
}
