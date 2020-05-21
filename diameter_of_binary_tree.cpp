//Path with highest number of nodes is the diameter of a binary tree
/*
 Given a binary tree, you need to compute the length of the diameter of the tree. 
 The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3]. 
*/

//Solution 1
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int option1=height(root->left)+height(root->right);
        int option2=diameterOfBinaryTree(root->left);
        int option3=diameterOfBinaryTree(root->right);
        return max(option1, max(option2, option3));
    }
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }

//Solution 2
class Solution {
public:
    int ans=0;
    int diameterOfBinaryTree(TreeNode* root)
    {
        
        if(root==nullptr)
            return 0;
        int left_subtree_height=height(root->left);
        int right_subtree_height=height(root->right);
        ans=max(ans, left_subtree_height+right_subtree_height+1);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return ans-1;
    }
    int height(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
};