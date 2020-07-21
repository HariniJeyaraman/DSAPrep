/*
129. Sum Root to Leaf Numbers
Medium

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
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
//Storing all possible root to leaf paths in the result vector and then calculating the sum
class Solution {
public:
    int sum=0;
    void preorder(TreeNode* root, vector<int>& curr, vector<vector<int>>& result){
       if(root!=NULL){
           if(root->left==NULL && root->right==NULL){
               curr.push_back(root->val);
               result.push_back(curr);
               curr.pop_back();
           }
           curr.push_back(root->val);
           preorder(root->left, curr, result);
           preorder(root->right, curr, result);
           curr.pop_back();
       }
    }
    
    int sumNumbers(TreeNode* root) {
        vector<int> curr;
        int temp=0;
        vector<vector<int>> result;
        if(root==NULL)
            return sum;
        preorder(root, curr, result);
        for(auto& val : result){
            for(auto& el : val){
             temp = temp*10 + el;   
            }
            sum+=temp;
            temp=0;
        }
        return sum;
    }
};