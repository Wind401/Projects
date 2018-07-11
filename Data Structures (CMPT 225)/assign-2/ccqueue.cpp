# include "ccqueue.h"
# include <iostream>
using namespace std;
CCQueue::CCQueue()
{
    maxticketid=0;
}
bool CCQueue::Add(string customer, string complaint)
{
    Ticket t1(maxticketid,customer, complaint);
    bool result=true;
    if(t1.GetCustomer()==" " || t1.GetComplaint()==" ")
    {
        result=false;
    }
    else
    {
      tickets.InsertBack(t1);
        maxticketid++;
    }

    return result;
}

Ticket CCQueue::Service()
{
    Ticket t1(tickets.ElementAt(0).GetID(),tickets.ElementAt(0).GetCustomer(),tickets.ElementAt(0).GetCustomer());
//    tickets<Ticket> ;
   // tickets.RemoveAt(0);
   return t1;
}
int CCQueue::Size() const
{
    return tickets.Size();
}
bool CCQueue::MoveUp(int index)
{
    Ticket t1(tickets.ElementAt(index).GetID(),tickets.ElementAt(index).GetCustomer(),tickets.ElementAt(index).GetComplaint());
    Ticket t2(tickets.ElementAt(index-1).GetID(),tickets.ElementAt(index-1).GetCustomer(),tickets.ElementAt(index-1).GetComplaint());
    bool result=true;
    if(index<=0)
    {
        result=false;
    }
    else
    {
       tickets.InsertAt(t1,index-1);
       tickets.InsertAt(t2,index);
       }
    return result;
}
bool CCQueue::MoveDown(int index)
{
    Ticket t1(tickets.ElementAt(index).GetID(),tickets.ElementAt(index).GetCustomer(),tickets.ElementAt(index).GetComplaint());
    Ticket t2(tickets.ElementAt(index+1).GetID(),tickets.ElementAt(index+1).GetCustomer(),tickets.ElementAt(index+1).GetComplaint());
    bool result=true;
    if(index<=0)
    {
        result=false;
    }
    else
    {
       tickets.InsertAt(t1,index+1);
       tickets.InsertAt(t2,index);
       }
    return result;
}
