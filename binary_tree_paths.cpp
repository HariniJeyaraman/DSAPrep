/*
257. Binary Tree Paths
Easy

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

//Solution 1
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
    void dfs(TreeNode *root, string temp, vector<string> &result){
        if(root!=NULL){
            temp+=to_string(root->val);
            if(root->left==NULL && root->right==NULL){
                result.push_back(temp);
                return;
            }
            if(root->left!=NULL)
            dfs(root->left,temp+"->",result);
            if(root->right!=NULL)
                dfs(root->right, temp+"->",result);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root==NULL)
            return result;
        string temp="";
        dfs(root, temp,result);
        return result;
    }
    
    
};