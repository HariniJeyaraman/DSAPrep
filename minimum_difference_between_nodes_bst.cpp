/*
783. Minimum Distance Between BST Nodes
Easy

Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
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
    void inorder(TreeNode* root, vector<int>& tree)
    {
        if(root!=NULL)
        {
            inorder(root->left, tree);
            tree.push_back(root->val);
            inorder(root->right, tree);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> tree;
        if(root==NULL)
            return 0;
        inorder(root, tree);
        int mindiff=INT_MAX;
        for(int i=0;i<tree.size();i++)
        {
            for(int j=i+1;j<tree.size();j++)
            {
                if(abs(tree[i]-tree[j])<(mindiff))
                    mindiff=abs(tree[i]-tree[j]);
            }
        }
        return mindiff;
    }
};