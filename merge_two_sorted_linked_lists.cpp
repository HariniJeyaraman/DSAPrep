/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15

The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
*/
#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *nptr;
};

struct node* hptr3=NULL;
struct node* hptr1=NULL;//head pointer of list1
struct node* hptr2=NULL;//head pointer of list2

void insertNode(struct node** hptr, int pos, int x)
{
    struct node *temp=new node;
    if(temp==NULL)
        cout<<"Insert not possible\n";
    temp->data=x;
    if(pos==1)
    {
        temp->nptr= *hptr;
        *hptr=temp;
    }
    else
    {
        int i=1;
        struct node* thptr=*hptr;
        while(i<pos-1)
        {
            thptr=thptr->nptr;
            i++;
        }
        temp->nptr=thptr->nptr;
        thptr->nptr=temp;
    }
}

void print(struct node** hptr)
{
    struct node* temp=*hptr;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->nptr;
    }
}

void mergeLists()
{
    struct node* hptr=new node;//create a new temporary node for the merged linked list to have something to build our list on
    hptr3=hptr;
    while(hptr1!=NULL && hptr2!=NULL)
    {
        if(hptr1->data<=hptr2->data)
        {
            hptr->nptr=hptr1;
            hptr1=hptr1->nptr;
        }
        else
        {
            hptr->nptr=hptr2;
            hptr2=hptr2->nptr;
        }
        hptr=hptr->nptr;
    }

    while(hptr1!=NULL)
    {
        hptr->nptr=hptr1;
        hptr1=hptr1->nptr;
        hptr=hptr->nptr;
    }

    while(hptr2!=NULL)
    {
        hptr->nptr=hptr2;
        hptr2=hptr2->nptr;
        hptr=hptr->nptr;
    }
    hptr3=hptr3->nptr;
}

int main()
{
    insertNode(&hptr1,1,1);
    insertNode(&hptr1,2,2);
    insertNode(&hptr1,3,4);
    insertNode(&hptr2,1,1);
    insertNode(&hptr2,2,3);
    insertNode(&hptr2,3,4);
    mergeLists();
    print(&hptr3);
    return 0;
}