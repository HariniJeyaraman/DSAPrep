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
//removing the nth node from the end faster using two pointers
/*
Take two pointers, first will point to the head of the linked list and second will point to the Nth node from the beginning.
Now keep increment both the pointers by one at the same time until second is pointing to the last node of the linked list.
After the operations from the previous step, first pointer should be pointing to the Nth node from the end by now.
So, delete the node first pointer is pointing to.
*/

//If we move the fast pointer to n th node from beginning, our slow pointer will point to the nth node from end (the node which should be deleted)
//But we can delete the target node only if we have a pointer to its previous node
//If slow points at the target node itself, we will not be able to delete it
//So we move our fast pointer to n+1 th position. That is, is our n is 3 (3rd node from last), instead of making fast point to 3rd node from beginning,
//we make fast point to the 4th node from beginning, so that slow points at node just before node to be deleted
void removeNthNode_faster(int n)
{
    struct node* slow_pointer=hptr;
    struct node* fast_pointer=hptr;
    int i=1;
    
    //moving fast pointer to the n+1 th node from the beginning
    while(i<n+1)
    {
        i++;
        if(fast_pointer->nptr!=NULL)
        fast_pointer=fast_pointer->nptr;
        else if(fast_pointer->nptr==NULL)
        {
            //if number of nodes/ size of ll <=n
            //delete 1st node
            if(i==n+1)
            {
                hptr=hptr->nptr;
                break;
            }
                
        }
    }

    while(fast_pointer->nptr!=NULL)
    {
        slow_pointer=slow_pointer->nptr;
        fast_pointer=fast_pointer->nptr;
    }

    //slow_pointer will now point just before the node to be deleted. If size-n+1 is the node to be deleted, it will point to (size-n) th position
    // so that we can delete the size-n+1 th position node
    if(slow_pointer!=NULL)
       slow_pointer->nptr=slow_pointer->nptr->nptr;
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
    insertNode(2,12);
    insertNode(3,13);
    insertNode(4,14);
    insertNode(5,15);
    insertNode(6,16);
    insertNode(7,17);
    // removeNthNode(3);
    removeNthNode_faster(7);
    print();
    return 0;
}