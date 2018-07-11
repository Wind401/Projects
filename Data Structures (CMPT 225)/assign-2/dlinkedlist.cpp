# ifdef _DLINKEDLIST_H_
# include <stdexcept>
# include "dlinkedlist.h"
# include <iostream>
using namespace std;
template <class T>
DLinkedList<T>::DLinkedList()
{
    size=0;
    front=NULL;
    back=NULL;
}
template <class T>
void DLinkedList<T>::DeleteList()
{
    Node<T>* temp=front;
    while(temp!=NULL)
    {
        temp=front->next;
        delete front;
        front=temp;
    }
    front=NULL;
}
template <class T>
void DLinkedList<T>::CopyList(const DLinkedList<T>& ll)
{

}
template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& ll)
{
    Node<T>* temp;
    temp=new Node<T>(ll.front->data);
    front=temp;
    Node<T>* temp1;
    temp1=ll.front;
    while(temp1->next!=NULL)
    {
        temp->next= new Node<T>(temp1->next->data);
        temp=temp->next;
        temp1=temp1->next;
    }
    back=temp;
    back->next=NULL;
    size=ll.Size();

}

template <class T>
void DLinkedList<T>::InsertBack(T item)
{
    Node<T>* temp;
    temp=new Node<T>(item);
     if(front==NULL)
    {
        front=temp;
        back=temp;
        size++;
    }
    else
    {
        back->next=temp;
        //temp->prev=back;
        //temp->next=NULL;
        back=temp;
        size++;
    }
}
template <class T>
void DLinkedList<T>::InsertFront(T item)
{
    Node<T>* temp;
    temp=new Node<T>(item);
    if(front==NULL)
    {
        front=temp;
        back=temp;
        size++;
    }
    else
    {
        temp->next=front;
        front->prev=temp;
        temp->prev=NULL;
        front=temp;
        size++;
    }
}

template <class T>
void DLinkedList<T>::InsertAt(T item, int P)
{
    Node<T>*temp;
    Node<T>* start;
    start=front;
    temp=new Node<T>(item);
    if(P>size || P<0)
    {
        throw out_of_range("Invalid Index");
    }
    else if(P==0)
    {
        InsertFront(item);
    }
    else if(P==size)
    {
        InsertBack(item);
    }
    else
    {
        for(int i=0;i<P-1;i++)
        {
            start=start->next;
        }
        temp->next=start->next;
        temp->next->prev=temp;
        start->next=temp;
        temp->prev=start;
//        cout<"yo";
        size++;
    }

}
template <class T>
T DLinkedList<T>::RemoveAt(int P)
{
    Node<T>* temp;
    int count=0;
    if(P>=size|| P<0 )
    {
        throw std::out_of_range("Invalid Index");
    }
else if(size==1)
{
    temp=front;
    front=NULL;
    back=NULL;
    delete temp;
    size--;

}
   else if(P==0 && size>1)
   {
    temp=front;
    front=front->next;
    front->prev=NULL;
    delete temp;
    size--;
    }
    else if(P==size-1 && size>1)
    {
        temp=back;
        back=back->prev;
       // back->next=NULL;
        delete temp;
        size--;
    }
    else
    {
    }

}
template <class T>
int DLinkedList<T>::Size() const
{
    return size;
}
template <class T>
DLinkedList<T>::~DLinkedList()
{
    DeleteList();
}
template <class T>
void DLinkedList<T>::RemoveDuplicates()
{
    Node<T>* ptr1;
    Node<T>* ptr2;
    Node<T>* temp;
    Node<T>* back_ptr;
    Node<T>* current;
    current=front;
    ptr1=front;
while(ptr1 != NULL && ptr1->next != NULL)
  {
     ptr2 = ptr1;
     while(ptr2->next != NULL)
     {
       if(ptr1->data == ptr2->next->data)
       {
          temp = ptr2->next;
          ptr2->next = ptr2->next->next;
          size--;
          delete temp;
       }
       else
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
    while(current->next!=NULL)
    {
        current=current->next;
    }
    back=current;
}

template <class T>
bool DLinkedList<T>::IsEmpty() const
{
    return size==0;
}
template <class T>
bool DLinkedList<T>::Contains(T item) const
{
    Node<T>* temp;
    bool result=false;
    temp=front;
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            result=true;
        }
        temp=temp->next;
    }
    return result;
}
template <class T>
T DLinkedList<T>::ElementAt(int P) const
{
    int count=0;
    Node<T>* temp;
    temp=front;
    if(P>=size|| P<0 || size==0)
    {
        throw std::out_of_range("Invalid Index");
    }
    else
    {
        while(count!=P)
        {
            temp=temp->next;
            count++;
        }
        return temp->data;
    }
}
template <class T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& ll)
{
    Node<T>* temp;
    temp=new Node<T>(ll.front->data);
    front=temp;
    Node<T>* temp1;
    temp1=ll.front;
    while(temp1->next!=NULL)
    {
        temp->next= new Node<T>(temp1->next->data);
        temp=temp->next;
        temp1=temp1->next;
    }
    back=temp;
    back->next=NULL;
    size=ll.Size();
    return *this;
}
#endif
