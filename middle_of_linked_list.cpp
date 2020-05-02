/*
Given a singly linked list, find middle of the linked list. For example, 
if given linked list is 1->2->3->4->5 then output should be 3.

If there are even nodes, then there would be two middle nodes, 
we need to print second middle element. For example, if given linked list is 1->2->3->4->5->6 then output should be 4.
*/
#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node* nptr;
};

struct node* hptr = NULL;

void insert(int pos, int x)
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

void middleNode()
{
    struct node* temp=hptr;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->nptr;
    }
    int i=1;
    temp=hptr;
    cout<<"Total nodes is : "<<count<<endl;
    while(i<=count/2)
    {
        temp=temp->nptr;
        i++;
    }
    cout<<"i is : "<<i<<endl;
    cout<<"Middle node is : "<<temp->data<<endl;
}

//A faster way with print the middle node
//Traverse linked list using two pointers.
// Move one pointer by one and other pointer by two. 
//When the fast pointer reaches end slow pointer will reach middle of the linked list.
void middleNode_faster()
{
    struct node* slow_pointer=hptr;
    struct node* fast_pointer=hptr;
    if(hptr!=NULL)
    {
        while(fast_pointer!=NULL && fast_pointer->nptr!=NULL)
        {
            slow_pointer=slow_pointer->nptr;
            fast_pointer=fast_pointer->nptr->nptr;
        }
        cout<<"The middle element is : "<<slow_pointer->data<<endl;
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
    insert(1,12);
    insert(2,13);
    insert(3,14);
    insert(4,15);
    insert(5,16);
    insert(6,22);
    middleNode();
    middleNode_faster();
    return 0;
}