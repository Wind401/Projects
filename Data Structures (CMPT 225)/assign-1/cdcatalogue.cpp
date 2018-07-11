# include "cdcatalogue.h"
# include <iostream>
using namespace std;
void CDCatalogue::CopyArray(const CDCatalogue& cat)
{
    CD *newcds=new CD[maxsize];
    for(int i=0;i<cat.Count();i++)
    {
        newcds[i]=cds[i];
    }
    delete[] cds;
    cds=newcds;
}
CDCatalogue::CDCatalogue()
{
 maxsize=4;
 cds=new CD[maxsize];
 numcds=0;
}
bool CDCatalogue::Insert(CD disc)
{
    bool result=false;
    if(disc.GetAlbum()=="" || disc.GetArtist()=="")
    {
        return -1;
    }
    else
    {
        if(numcds>=maxsize)
        {
           CD *newcds=new CD[2*maxsize];
            for(int i=0;i<maxsize;i++)
            {
                newcds[i]=cds[i];
            }
        delete[] cds;
        cds=newcds;
        }
        for(int i=0;i<numcds;i++)
        {
            if(disc.GetAlbum()==cds[i].GetAlbum() && disc.GetArtist()==cds[i].GetArtist())
            {
                return result;
            }
        }
        if(!result)
            {
                cds[numcds].Update(disc.GetArtist(),disc.GetAlbum());
                numcds++;
                return !result;
            }
    }
   return 0;
}
bool CDCatalogue::Remove(CD disc)
{

    bool result=false;
    CD temp;
    if(disc.GetAlbum()=="" || disc.GetArtist()=="")
    {
        return -1;
    }
    else
    {
        for(int i=0;i<=numcds+1;i++)
        {
            if(disc.GetAlbum()==cds[i].GetAlbum() || disc.GetArtist()==cds[i].GetArtist())
            {
                temp=cds[i];
                cds[i]=cds[numcds-1];
                cds[numcds-1]=temp;
                numcds--;
                result=true;
            }
        }
        if( numcds==1 && (disc.GetAlbum()==cds[0].GetAlbum() || disc.GetArtist()==cds[0].GetArtist()))
        {
             numcds--;
        }
        if(result)
        {
            return !result;
        }
        else
        {
            return result;
        }

    }
    return 0;
}
int CDCatalogue::Count() const
{
    return numcds;
}
CDCatalogue::~CDCatalogue()
{
}
CDCatalogue::CDCatalogue(const CDCatalogue &cat)
{

    numcds=cat.Count();
    int maxsize=4;
    cds= new CD[maxsize];
    for(int i=0;i<numcds;i++)
    {
        cds[i]=cat.cds[i];
    }


}
int CDCatalogue::Find(CD disc) const
{
    bool result=false;
    int temp_int;
     if(disc.GetAlbum()=="" || disc.GetArtist()=="")
    {
        return -1;
    }
    else
    {
    for(int i=0;i<numcds;i++)
    {
        if(disc.GetAlbum()==cds[i].GetAlbum() && disc.GetArtist()==cds[i].GetArtist())
        {
            temp_int=i;
            result=true;
            return result;
             }
    }
    if(result)
    {
        return temp_int+1;
    }
    else
    {
        return -1;
    }
    }
}
bool CDCatalogue::Boycott(string dontlikeanymore)
{
    bool result=false;
    CD temp;
     if(dontlikeanymore==" ")
    {
        return -1;
    }
    else
    {
    for(int i=0;i<=numcds+1;i++)
    {
        if(cds[i].GetArtist()==dontlikeanymore)
        {
            temp=cds[i];
            cds[i]=cds[numcds-1];
            cds[numcds-1]=temp;
            numcds--;
            result=true;
        }
    }
    if( numcds==1 && cds[0].GetArtist()==dontlikeanymore)
        {
             numcds--;
        }
    if(result)
    {
        return result;
    }
    else
    {
        return !result;
    }
    }
}
CDCatalogue CDCatalogue::Join(const CDCatalogue &cat) const
{
    CDCatalogue temp;
    int temp_int=numcds;
    CD temp_cd;
    temp.cds=new CD[numcds+cat.Count()];
    for(int i=0;i<numcds;i++)
    {
        temp.cds[i]=cds[i];
    }
    for(int i=0;i<cat.Count();i++)
    {
        temp.cds[temp_int]=cat.cds[i];
        temp_int++;
    }
   for(int i=0;i<=temp_int;i++)
    {
        for(int j=i+1;j<temp_int;j++)
        {
            if(temp.cds[i].GetAlbum()==temp.cds[j].GetAlbum() && temp.cds[i].GetArtist()==temp.cds[j].GetArtist())
            {
                temp_cd=temp.cds[temp_int-1];
                temp.cds[temp_int-1]=temp.cds[j];
                temp.cds[j]=temp_cd;
                temp_int--;
            }
        }
    }
    temp.numcds=temp_int;
    return temp;
}
CDCatalogue CDCatalogue::Common(const CDCatalogue &cat) const
{
     CDCatalogue temp;
    int temp_int=numcds;
    CD temp_cd;
    int top=0;
    temp.cds=new CD[numcds+cat.Count()];
    for(int i=0;i<numcds;i++)
    {
        temp.cds[i]=cds[i];
    }
    for(int i=0;i<cat.Count();i++)
    {
        temp.cds[temp_int]=cat.cds[i];
        temp_int++;
    }
    for(int i=0;i<=temp_int;i++)
    {
        for(int j=i+1;j<temp_int;j++)
        {
            if(temp.cds[i].GetAlbum()==temp.cds[j].GetAlbum() && temp.cds[i].GetArtist()==temp.cds[j].GetArtist())
            {
                temp_cd=temp.cds[top];
                temp.cds[top]=temp.cds[j];
                temp.cds[j]=temp_cd;
                top++;
            }
        }
    }
    temp.numcds=top;
    return temp;
}
CDCatalogue CDCatalogue::Split(const CDCatalogue &cat) const
{
     CDCatalogue temp;
    int temp_int=numcds;
    CD temp_cd;
    int top=0;
    int bottom=0;
    temp.cds=new CD[numcds+cat.Count()];
    for(int i=0;i<numcds;i++)
    {
        temp.cds[i]=cds[i];
        top++;
    }
    for(int i=0;i<cat.Count();i++)
    {
        temp.cds[temp_int]=cat.cds[i];
        temp_int++;
    }
    while(top!=temp_int)
    {
        for(int i=0;i<top;i++)
        {
            if(temp.cds[i].GetAlbum()!=temp.cds[top].GetAlbum() && temp.cds[i].GetArtist()!=temp.cds[top].GetArtist())
            {
                temp_cd=temp.cds[bottom];
                temp.cds[bottom]=temp.cds[i];
                temp.cds[i]=temp_cd;
                bottom++;
                break;
            }
        }
        top++;
    }
    temp.numcds=bottom;
    return temp;
}
