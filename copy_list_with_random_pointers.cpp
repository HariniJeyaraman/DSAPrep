/*
38. Copy List with Random Pointer
Medium

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
Example 1:

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//This is O(N) time and space solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* temp = head;
        if(head==NULL)
            return NULL;
        Node* new_node = new Node(head->val);
        Node* head2 = new_node;
        //copying just the nodes without the random pointer
        temp=temp->next;
        while(temp!=NULL){
        Node* node = new Node(temp->val);
        new_node->next = node;
        new_node = node;
        temp=temp->next;
        }
        
        temp = head;
        Node *temp2 = head2;
        while(temp!=NULL){
            map[temp] = temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
        
        //copying the random pointer pattern from original to copy of linked list
        temp=head;
        temp2 = head2;
        while(temp!=NULL){
            Node *rand_orig = temp->random;
            Node *rand_copy = map[rand_orig];
            temp2->random = rand_copy;
            temp=temp->next;
            temp2 = temp2->next;
        }
        
        return head2;
    }
};
