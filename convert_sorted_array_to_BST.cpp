/*
108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

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
 
 //We use Binary Search
 //The middle of the sorted array will be the root node and the middle of the left subarray will the the left subtree root and 
 //middle of the right subarray will be the root node of the right subtree.
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        return BSTconstruct(nums,0,nums.size()-1);
    }
    TreeNode* BSTconstruct(vector<int> nums, int beg, int end)
    {
        if(beg>end)
            return NULL;
        int mid=beg+(end-beg)/2;
        TreeNode *newnode=new TreeNode(nums[mid]);
        newnode->left=BSTconstruct(nums, beg, mid-1);
        newnode->right=BSTconstruct(nums,mid+1,end);
        return newnode;
    }
};