/*
285. Inorder Successor in BST
Medium

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

 

Example 1:

Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.

Example 2:

Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 

Note:

If the given node has no in-order successor in the tree, return null.
It's guaranteed that the values of the tree are unique.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p==NULL)
            return NULL;
        //Case 1 : Node has right subtree
        if(p->right!=NULL){
            TreeNode* current = p->right;
            while(current->left!=NULL)
                current=current->left;
            return current;
        }
        //Case 2 : Node does not have right subtree
        //Case 2a : If the node p is a left child,deepest ancestor will be its parent.Return parent of p
        //Case 2b : If the node p is a right child, its parent is already visited, return the deepest ancestor to which p lies in left subtree
        else{
            //Find the deepest ancestor to which p is in left subtree
            TreeNode* ancestor=root;
            TreeNode* inorder_successor=NULL;
            while(ancestor!=p){
                if(p->val<ancestor->val){
                    inorder_successor=ancestor;
                    ancestor=ancestor->left;
                }
                else
                    ancestor=ancestor->right;
            }
            return inorder_successor;
        }
        
        
    }
};