/*
Delete Node in a Linked List
Approach: Swap with Next Node [Accepted]

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:

 

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your 
*/

/*
The usual way of deleting a node node from a linked list is to modify the next pointer of the node before it, to point to the node after it.

Since we do not have access to the node before the one we want to delete, we cannot modify the next pointer of that node in any way. 

Instead, we have to replace the value of the node we want to delete with the value in the node after it, and then delete the node after it.

Because we know that the node we want to delete is not the tail of the list, we can guarantee that this approach is possible.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        struct ListNode *current=node;
        current->val=current->next->val;
        current->next=current->next->next;
    }
};