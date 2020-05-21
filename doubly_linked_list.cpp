//Implementation of doubly linked list
#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *nptr; //next pointer
    struct node *pptr; //previous pointer
};

struct node* hptr=NULL; //head pointer

void insertNode(int pos, int x)
{
    struct node *temp=new node;
    if(temp==NULL)
        cout<<"Insertion not possible\n";
    temp->data=x;
    if(pos==1 && hptr==NULL)
    {
        temp->pptr=NULL;
        temp->nptr=NULL;
        hptr=temp;
    }
    else if(pos==1)
    {
        temp->nptr=hptr;
        hptr=temp;
        temp->nptr->pptr=temp;
        temp->pptr=NULL;
    }
    else
    {
        int i=1;
        struct node *thptr=hptr;
        while(i<pos-1)
        {
            thptr=thptr->nptr;
            i++;
        }
        temp->nptr=thptr->nptr;
        temp->pptr=thptr;
        thptr->nptr=temp;
        thptr->nptr->pptr=thptr;
    }
}

void deleteNode(int pos)
{
    if(hptr==NULL)
        cout<<"Deletion not possible\n";
    else
    {
        
        if(pos==1)
        {
            hptr=hptr->nptr;
        }
        else
        {
            int i=1;
            struct node *thptr=hptr;
            while(pos<i-1)
            {
                thptr=thptr->nptr;
            }
            thptr->nptr=thptr->nptr->nptr;
            if(thptr->nptr!=NULL)
                thptr->nptr->pptr=thptr;
        }
        
    }
}

void print()
{
    struct node *thptr=hptr;
    while(thptr!=NULL)
    {
        cout<<thptr->data<<"\n";
        thptr=thptr->nptr;
    }
    // cout<<endl;
}

int main()
{
    insertNode(1,11);
    insertNode(2,12);
    insertNode(3,13);
    insertNode(4,14);
    insertNode(5,15);
    print();
    return 0;
}