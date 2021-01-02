/*
513. Find Bottom Left Tree Value
Medium

Given the root of a binary tree, return the leftmost value in the last row of the tree.
Example 1:

Input: root = [2,1,3]
Output: 1

Example 2:

Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
*/
class Solution {
public:
    int result = -1, l=-1;
    void helper(TreeNode* root, int level){
        if(root==NULL) return;
        helper(root->left, level+1);
        if(level > l) {
            result = root->val;
            l = level;
        }
        helper(root->right, level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return -1;
        helper(root,1);
        return result;
    }
};