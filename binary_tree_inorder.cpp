/*
94. Binary Tree Inorder Traversal
Medium

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>& result)
    {
         if(root!=NULL)
        {
            inorder(root->left, result);
            result.push_back(root->val);
            inorder(root->right, result);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> result;
        inorder(root, result);
        return result;
    }
};