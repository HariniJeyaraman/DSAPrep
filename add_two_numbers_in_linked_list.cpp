/*
Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        int carry=0;
        ListNode* l3=dummy;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=NULL || temp2!=NULL)
        {
            int val1=(temp1!=NULL)?temp1->val:0;
            int val2=(temp2!=NULL)?temp2->val:0;
            int sum=val1+val2+ carry;
            // dummy->val=(sum)%10;
            carry=sum/10;
            
            ListNode *newnode=new ListNode(sum%10);
            l3->next=newnode;
            if(temp1!=NULL)
            temp1=temp1->next;
            if(temp2!=NULL)
            temp2=temp2->next;
            l3=l3->next;
        }
        if(carry>0)
        {
            ListNode *newnode=new ListNode(carry);
            l3->next=newnode;
            l3=l3->next;
        }
        return dummy->next;
    }
};