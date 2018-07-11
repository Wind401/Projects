# include "hashtable.h"
# include "slinkedlist.h"
# include <vector>
# include <iostream>
using namespace std;

HashTable::HashTable()
{
    size=0;
    maxsize=101;
    table =new SLinkedList<UserAccount>[maxsize];
}
bool HashTable::IsPrime(int n) const
{
    if (n != 0)
    {
        int half;
        if (n%2 == 0)
        {
            half  = n/2;
        }
        else
        {
            half = n/2 + 1;
        }

        for (int i = 2; i <= half; i++)
        {
            if (n%i == 0)
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}
int HashTable::SmallestPrime(int n) const
{
    int start = n+1;
    while(IsPrime(start) == false)
    {
        start++;
    }
    return start;
}

HashTable::HashTable(int n)
{
    size=0;
    maxsize=SmallestPrime(2*n);
    table=new SLinkedList<UserAccount>[maxsize];
  // cout<<maxsize<<endl;
}
HashTable::~HashTable()
{
     for (int i = 0; i < maxsize; i++)
    {
        if (table[i].Size()!=0)
        {
            table[i].RemoveAll();
        }
    }
}
int HashTable::Hash(string input) const
{
    int asc = 0;
    int value = 1;
    for(int i = 0; i < input.size(); i++)
    {
		asc = input[i] - 96;
		if (i == 0)
        {
            value = asc % maxsize;
        }
        else
        {
            value = (value*32 + asc) % maxsize;
        }
    }
    return value;
}

bool HashTable::Resize(int n)
{
    if (n < maxsize || n<0)
    {
        return false;
    }
    else
    {
		int oldmaxsize = maxsize;
        maxsize = SmallestPrime(2*n);
        SLinkedList<UserAccount> *newtable = new SLinkedList<UserAccount>[maxsize];

        // do copy
        for (int i = 0; i < oldmaxsize; i++)
        {
            if(table[i].Size() != 0)
            {
                vector<UserAccount> val = table[i].Dump();
                //cout<<val[0].GetUsername();
                for (int j = 0; j < table[i].Size(); j++)
                {
                    // insert in new table using new hash
                   int hashval=Hash(val[j].GetUsername());
                    //int hashval = Hash(val[j]);
                    newtable[hashval].InsertFront(val[j]);
                }
                table[i].RemoveAll();
            }
        }
        table = newtable;
        return true;
    }
}
bool HashTable::Insert(UserAccount acct)
{
    if(LoadFactor()>=0.67)
    {
        Resize(SmallestPrime(MaxSize()));
    }
     int hashval = Hash(acct.GetUsername());
    if (table[hashval].Contains(acct))
    {
        return false;
    }
    else
    {
        table[hashval].InsertBack(acct);
        size++;
        //cout<<Size()<<endl;
        //cout<<MaxSize()<<endl;
        //cout<<hashval;
        return true;
    }
}
bool HashTable::Remove(UserAccount acct)
{
    int hashval = Hash(acct.GetUsername());


    if (table[hashval].Contains(acct))
    {
        table[hashval].Remove(acct);
        size--;
        return true;
    }
    else
    {
        return false;
    }
}
bool HashTable::Search(UserAccount acct) const
{
    int hashval = Hash(acct.GetUsername());
    return table[hashval].Contains(acct);
}

int HashTable::Size() const
{
    return size;
}

int HashTable::MaxSize() const
{
    return maxsize;

}
double HashTable::LoadFactor() const
{
    return Size()/MaxSize();

}
UserAccount* HashTable::Retrieve(UserAccount acct)
{
     int hashval = Hash(acct.GetUsername());
     //cout<<hashval;
    return table[hashval].Retrieve(acct);
    }

HashTable& HashTable::operator=(const HashTable& sourceht)
{
    if (this != &sourceht)
    {
        // Remove All
            for (int i = 0; i < maxsize; i++)
        {
            if (table[i].Size()!=0)
            {
                table[i].RemoveAll();
            }
        }

        // Do copy
        size = sourceht.Size();
        maxsize = sourceht.MaxSize();
        for (int i = 0; i < maxsize; i++)
        {
            if (sourceht.table[i].Size()!= 0) // if i'th linked list is not empty
            {
                // do copy
                vector<UserAccount> frmsource = sourceht.table[i].Dump();
                for (int j = sourceht.table[i].Size() - 1; j >= 0; j--)
                {
                    table[i].InsertBack(frmsource[j]);
                }
            }
        }
    }
    return *this;
}
HashTable::HashTable(const HashTable& sourceht)
{
    size = sourceht.Size();
    maxsize = sourceht.MaxSize();
    table = new SLinkedList<UserAccount>[maxsize];
    for (int i = 0; i < maxsize; i++)
    {
        if (sourceht.table[i].Size()!= 0) // if i'th linked list is not empty
        {
            // do copy
            vector<UserAccount> val = sourceht.table[i].Dump(); // create vector to get the values
            for (int j = sourceht.table[i].Size() - 1; j >= 0; j--)
            {
                table[i].InsertBack(val[j]);
            }
        }
    }
}
