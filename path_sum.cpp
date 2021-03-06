/*
112. Path Sum
Easy

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

//In this problem, we use DFS to travel from root to leaf. The inorder,preorder and postorder traversals are a type of DFS
//We will use pre order DFS for this problem. As and when we traverse a node, we subtract the value of that node from the 
//sum and pass this subtracted sum to the next node, and so on.
//if the last node/leaf node has value same as sum, we return true.

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
    bool hasPathSum(TreeNode* root, int sum) {
     //base case
     if(root==NULL)
         return false;
     //base cases
     //if leaf node has value equal to sum, return true
     if(root->left==NULL && root->right==NULL && root->val == sum)
         return true;
     if(root->left==NULL && root->right==NULL && root->val!=sum)
         return false;
     //update the sum after traversing each node
     sum=sum-root->val;

     if(hasPathSum(root->left, sum)) return true;
     if(hasPathSum(root->right, sum)) return true;
     return false;
    }
};

class Solution {
public:
    bool dfs(TreeNode* root, int target, int currentSum){
        if(root==NULL)
            return false;
        currentSum+=root->val;
        if(root->left==NULL && root->right==NULL && currentSum==target)
            return true;
        return dfs(root->left, target, currentSum) || dfs(root->right, target, currentSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return dfs(root, targetSum, 0);
    }
};
