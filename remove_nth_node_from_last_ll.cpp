/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

If n is greater than the size of the list, remove the first node of the list.
*/
#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    struct node* nptr;
};
struct node* hptr=NULL;

void insertNode(int pos, int x)
{
    struct node* temp=new node;
    if(temp==NULL)
        cout<<"Insert not possible\n";
    temp->data=x;
    if(pos==1)
    {
        temp->nptr=hptr;
        hptr=temp;
    }
    else
    {
        int i=1;
        struct node* thptr=hptr;
        while(i<pos-1)
        {
            thptr=thptr->nptr;
            i++;
        }
        temp->nptr=thptr->nptr;
        thptr->nptr=temp;
    }

}

void deleteNode(int pos)
{
    struct node *temp=hptr;
    int i=1;
    if(temp==NULL)
        cout<<"Delete not possible\n";
    if(pos==1)
        hptr=hptr->nptr;
    else
    {
        while(i<pos-1)
        {
            temp=temp->nptr;
            i++;
        }
        temp->nptr=(temp->nptr)->nptr;
    }
}


void removeNthNode(int n)
{
    struct node* temp=hptr;
    int size=0;
    while(temp!=NULL)
    {
        size++;
        temp=temp->nptr;
    }
    temp=hptr;
    if(n>size)
    {   
        hptr=hptr->nptr;
    }
    else
    {
        int ind=size-n+1;
       deleteNode(ind);
    }
}

void print()
{
    struct node* temp=hptr;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->nptr;
    }
}

int main()
{
    insertNode(1,11);
    // insertNode(2,12);
    // insertNode(3,13);
    // insertNode(4,14);
    // insertNode(5,15);
    // insertNode(6,16);
    // insertNode(7,17);
    removeNthNode(1);
    print();
    return 0;
}