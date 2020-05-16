//Reverse a linked list using 3 pointers
#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *nptr;
};
struct node *hptr=NULL;

void insertNode(int pos, int x)
{
    struct node *temp=new node;
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

void reverseList()
{
    struct node* current=hptr;
    struct node* next;
    struct node* prev=NULL;
    while(current!=NULL)
    {
        next=current->nptr;
        current->nptr=prev;
        prev=current;
        current=next;
    }
    hptr=prev;
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
    insertNode(1,10);
    insertNode(2,20);
    insertNode(3,30);
    insertNode(4,40);
    insertNode(5,50);
    reverseList();
    print();
    return 0;
}