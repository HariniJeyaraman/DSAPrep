/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       
        if(head==NULL || head->next==NULL)
            return head;
        struct ListNode *a=head;
        struct ListNode *b=head->next;
        struct ListNode *even=b;//marks the start position of the even valued nodes 
        struct ListNode *temp_a=a; //copy of pointer a if a becomes NULL 
        
        while(b!=NULL && a!=NULL)
        {
            if(a!=NULL && b->next!=NULL)
            a->next=b->next;
            if(b->next!=NULL)
            a=b->next;
            else
            {
                temp_a=a;
                a=b->next;
            }
            if(b!=NULL && a!=NULL)
            b->next=a->next;
            if(a!=NULL)
            b=a->next;
        }
        //The position of a after the while loop indicates the end of odd nodes after linking
        //Linking the end of odds to the start of the evens
        if(a==NULL)
            temp_a->next=even;
        else
        a->next=even;
        return head;
    }
};

//Similar solution in better format :
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       if(head==NULL || head->next==NULL)
           return head;
        struct ListNode *odd=head;
        struct ListNode *even=head->next;
        struct ListNode *evenStart=even;
        while(even!=NULL && even->next!=NULL)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenStart;
        return head;
    }
};
