# ifdef _SLINKEDLIST_H_
#include "slinkedlist.h"

// default constructor
template <class T>
SLinkedList<T>::SLinkedList()
{
	front = NULL;
	size = 0;
	back=NULL;
}

// destructor
template <class T>
SLinkedList<T>::~SLinkedList()
{
	RemoveAll();
}


// copy constructor
// deep copies source list
template <class T>
SLinkedList<T>::SLinkedList(const SLinkedList<T>& ll)
{
	CopyList(ll);
}


// overloaded assignment operator
// deep copies source list after deallocating existing memory (if necessary)
template <class T>
SLinkedList<T>& SLinkedList<T>:: operator=(const SLinkedList<T>& ll)
{
	if (this != &ll)
	{
		CopyList(ll);
	}
	return *this;
}

// helper method for deep copy
template <class T>
void SLinkedList<T>::CopyList(const SLinkedList<T>& ll)
{
	//RemoveAll();
	front = NULL;
	size = ll.size;

	if (ll.front != NULL)
	{
		Node<T>* firstTemp = ll.front; // first of ll
		Node<T>* first = new Node<T>(firstTemp->data); // first for new list
		front = first; // head is first
		Node<T>* temp = front;
		while (firstTemp->next != NULL)
		{

			firstTemp = firstTemp->next;
			Node<T>* first = new Node<T>(firstTemp->data);
			temp->next = first;
			temp = temp->next;
		}
	}
}

// Inserts an item at the front of the list
template <class T>
void SLinkedList<T>::InsertFront(T s)
{

	Node<T>*temp=new Node<T>(s);
	Node<T>*start=front;
	if(front==NULL)
	{
	front=temp;
	temp->next=NULL;
	size++;
	}
	else
	{
        start=front;
        front=temp;
        front->next=start;
        size++;
	}

}
template <class T>
void SLinkedList<T>::InsertBack(T item)
{
    Node<T>* temp=new Node<T>(item);
    Node<T>* start=front;
    if(front==NULL)
    {
        front=temp;
        temp->next=NULL;
        size++;
    }
    else
    {
        while(start->next!=NULL)
        {
            start=start->next;
        }
        temp->next=NULL;
        start->next=temp;
        size++;
    }
}
template <class T>
T* SLinkedList<T>::Retrieve(T item)
{
 Node<T>*temp=front;
  T *data_pointer;
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            data_pointer=&temp->data;
            return data_pointer;
        }
        temp=temp->next;
    }
    return NULL;
    //return &item;

}
// Removes an item from the list.
// Returns true if item successfully removed
// False if item is not found
template <class T>
bool SLinkedList<T>::Remove(T s)
{
	if (size != 0 && size != 1)
	{
		Node<T>* temp = front;
		Node<T>* prevnode = NULL;
		for (unsigned int i = 0; i < size; i++)
		{
			if (temp->data == s)
			{
				if (prevnode != NULL) // is prevnode is not NULL, this is the case only when its not head
				{
					prevnode->next = temp->next;
				}
				else // when head
				{
					front = front->next;
				}
				delete temp;
				size--;
				return true;
			}
			else
			{
				prevnode = temp;
				temp = temp->next;
			}
		}
		return false;
	}
	else if (size == 1)
	{
		if (front->data == s)
		{
			front = NULL;
			size--;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


// Removes all items from the list, calls helper function
template <class T>
void SLinkedList<T>::RemoveAll()
{
	Node<T>* newnode = front;
	while (newnode != NULL)
	{
		front = front->next;
		delete newnode; // delete current
		newnode=front;
	}
	front = NULL;
	newnode=NULL;
	size = 0;
}

// Checks if an item exists in the list
template <class T>
bool SLinkedList<T>::Contains(T s)const
{
	/*Node<T>* temp = front;
	for (int i = 0; i < size; i++)
	{
		if (temp->data== s)
		{
			return true;
		}
		else
		{
			temp = temp->next;
		}
	}
	return false;*/
	Node<T>*temp=front;
	while(temp!=NULL)
	{
        if(temp->data==s)
        {
            //cout<<"Entered loop"<<endl;
            return true;
        }
        temp=temp->next;
	}
	return false;
	/*
	bool result=true;
	while(temp!=NULL)
	{
        if(temp->data==s)
        {
            return result;
        }
        temp=temp->next;
	}
	return !result;*/
}


// Return the number of items in the list
template <class T>
int SLinkedList<T>::Size() const
{
	return size;
}

// Returns a vector containing the list contents using push_back
template <class T>
vector<T>SLinkedList<T>::Dump() const
{
	vector<T> v;
	Node<T>* temp = front;
	while (temp != NULL)
	{
		v.push_back(temp->data);
		temp = temp->next;
	}
	return v;
}
template <class T>
bool SLinkedList<T>::IsEmpty() const
{
    //return size==0;
    return front==NULL;
}

#endif
												// For Testing only
//void LinkedList::PrintVector(vector<string> v)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout<<i+1<<". "<<v[i]<<endl;
//	}
//}
