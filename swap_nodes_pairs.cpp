 /*
 Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

*/
 ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        struct ListNode *prev=head;
        struct ListNode *current=head->next;
        struct ListNode *n = current->next;
        if(head->next->next==NULL) //only 2 nodes present in  list
        {
            head=current;
            prev->next=NULL;
            current->next=prev;
            return head;
        }
        head=current;
        while(current!=NULL)
        {
            current->next=prev;
            if(n!=NULL && n->next!=NULL && prev!=NULL)//if linked list has even nodes
                prev->next=n->next;
            else if(n->next==NULL) //if linked list has odd nodes
                prev->next=n;
            prev=n;
            if(prev!=NULL) 
            current=prev->next;
             if(current==NULL || current->next==NULL)
             {

                 prev->next=NULL;
                 if(current!=NULL)
                 current->next=prev;
                 break;
             }
            n=current->next;
            
        }
        return head;
       
    }