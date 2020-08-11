/*
226. Invert Binary Tree
Easy

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Swap each node's left and right children
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        
        TreeNode* temp = root->right;
        root->right=root->left;
        root->left=temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    
};