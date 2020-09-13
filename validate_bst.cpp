/*
98. Validate Binary Search Tree
Medium

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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
 //To make sure that a given right subtree node is > ALL its parent, and to make  sure that a left subtree node is <= all its parent
 //we maintain a range : min and max value that each node should lie between
class Solution {
public:
    bool helper(TreeNode* root, int min, int max){
        if(root==NULL)
            return true;
        if(min != -1 && root->val <= min)
            return false;
        if(max!=-1 && root->val >= max)
            return false;
        return helper(root->left,min,root->val) && helper(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,-1,-1);
    }
};

//Using inorder traversal
class Solution {
public:
    vector<int> in;
    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            in.push_back(root->val);
            inorder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        inorder(root);
        vector<int> temp=in;
        //left node val < root (strictly less than) so no duplicates allowed
        for(int i=0;i<in.size()-1;i++)
            if(in[i]==in[i+1])
                return false;
        sort(temp.begin(), temp.end());
        for(int i=0;i<temp.size();i++)
            if(temp[i]!=in[i])
                return false;
        return true;
    }
};

//Using inorder traversal without vector or array to store inorder values
//using prev pointer
class Solution {
public:
   TreeNode* prev=NULL;
    TreeNode* first;
    int f=0;
    void inorder(TreeNode* root){
        if(root==NULL)
            return ;
        
            inorder(root->left);
            if(prev!=NULL && root->val<=prev->val)
               f=-1;
            prev=root;
            inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        first=root;
        if(root==NULL) return true;
        inorder(root);
        if(f==-1) return false;
        return true;
        //left node val < root (strictly less than) so no duplicates allowed
        
    }
};