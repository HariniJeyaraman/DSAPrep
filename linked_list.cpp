//Implement Linked List
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

struct node
{
    int data;
    struct node* nptr;
};

struct node* hptr=NULL;

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
    deleteNode(3);
    print();
    return 0;
}
