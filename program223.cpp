//Singly Linear LinkedList using C++       //Generic program

#include<iostream>
using namespace std;


template <typename T>
struct node
{
    T data;
    struct node *next;
};


template <class T>
class SinglyLL
{
	private:
		 node <T> * first;
		int size;
    
	public:
		SinglyLL();
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
SinglyLL<T> :: SinglyLL()
    {
        first = NULL;
        size = 0;
    }
    
	
	template <class T>
    void SinglyLL<T> :: InsertFirst(T no)
    {
        node <T> * newn = new node <T>; 
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
    
	
	template <class T>
    void SinglyLL<T> :: InsertLast(T no)
    {
        node <T> * newn = new  node <T>;  
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            node <T> * temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
			
            temp->next = newn;
        }
        size++;
    }
    
	
	template <class T>
    void SinglyLL<T> :: InsertAtPos(T no, int ipos)
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
			node <T> * newn = new  node <T>; 
			node <T> * temp = first;
			
			if(newn == NULL)
			{
				return;
			}
			
			newn -> data = no;
			newn -> next = NULL;
			
			for(int i = 1; i < ipos-1; i++)
			{
				temp = temp -> next;
			}
			
			newn -> next = temp -> next;
			temp -> next = newn;
		}
		
		size++;
	}
    
	
	template <class T>
    void SinglyLL<T> :: DeleteFirst()
    {
        node <T> * temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }
    
	
	template <class T>
    void SinglyLL<T> :: DeleteLast()
    {
        node <T> * temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }
	
	
	template <class T>
    void SinglyLL<T> :: DeleteAtPos(int ipos)
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
			node <T> * targeted = NULL;
			
			for(int i = 1; i < ipos-1; i++)
			{
				temp = temp -> next;
			}
			
			targeted = temp -> next;
			temp -> next = targeted -> next;
			delete targeted;
		}
		size--;
	}
    
	
	template <class T>
    void SinglyLL<T> :: Display()
    {
        node <T> *  temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
	
	template <class T>
    int SinglyLL<T> :: Count()
    {
        return size;
    }


//////////////////////////////////////////////////////////////////////
int main()
{
	int iret = 0;
	
	SinglyLL <char> cobj;                  //char
	
    
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
	
	SinglyLL <int> iobj;                  //int
	
    
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
