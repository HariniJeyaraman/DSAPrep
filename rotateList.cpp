//Rotate linked list right by k nodes
#include<iostream>
#include<cstdlib>
#include<vector>

struct node
{
    int data;
    struct node *nptr;
};
struct node* hptr=NULL;

void insertNode(int pos, int x)
{
    struct node *temp=new node;
    if(temp==NULL)
        std::cout<<"Insert not possible\n";
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
        std::cout<<"Delete not possible\n";
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
        std::cout<<temp->data<<"\n";
        temp=temp->nptr;
    }
}

void rotateList(int k)
{
    //Finding the size of the linked list
    struct node* temp=hptr;
    struct node* start=hptr;
    struct node* ttemp=hptr;
    int size=0;
    while(temp!=NULL)
    {
        size++;
        ttemp=temp;//will point to the penultimate node
        temp=temp->nptr;
    }
    int rotateRightby=k%size; //If size of ll is 5 and k is 8, then it is equivalent to rotating by 3 instead of 8
    //The head pointer must point at position size - k
    int i=1;
    struct node *thptr=hptr;
    while(i<(size-rotateRightby))
    {
        i++;
        thptr=thptr->nptr;
    }
    if(thptr->nptr!=NULL)
    hptr=thptr->nptr; //updating the head pointer after the rotate right operation
    ttemp->nptr=start;//making the last node to point to the first node
    thptr->nptr=NULL;
}

int main()
{
    insertNode(1,10);
    insertNode(2,20);
    insertNode(3,30);
    insertNode(4,40);
    insertNode(5,50);
    rotateList(2);
    print();
    return 0;
}