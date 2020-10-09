/*
103. Binary Tree Zigzag Level Order Traversal
Medium

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        int c=0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> t;
            c++;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                t.push_back(temp->val);
                q.pop();
                if(temp->left!=NULL) {q.push(temp->left);}
                if(temp->right!=NULL) {q.push(temp->right);}
            }
            if(c%2==0)
            reverse(t.begin(), t.end());
            result.push_back(t);
        }
        return result;
    }
};