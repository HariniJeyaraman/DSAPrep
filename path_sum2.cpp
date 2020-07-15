/*
113. Path Sum II
Medium

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    void path(TreeNode* root, int sum, vector<int> &curr, vector<vector<int>> &result)
    {
        if(root!=NULL){
        if(root->left==NULL && root->right==NULL && root->val==sum)
        {
            curr.push_back(root->val);
            result.push_back(curr);
            curr.pop_back();
            //return true;
        }
        //if(root->left==NULL && root->right==NULL && root->val!=sum)
          //  return false;
        sum=sum-root->val;
        curr.push_back(root->val);
        if(root->left)
        path(root->left, sum, curr, result);
        if(root->right)
        path(root->right, sum, curr, result);
        curr.pop_back();}
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
       vector<vector<int>> result;
        if(root==NULL)
            return result;
        vector<int> curr;
        path(root, sum, curr, result);
        return result;
            
    }
};