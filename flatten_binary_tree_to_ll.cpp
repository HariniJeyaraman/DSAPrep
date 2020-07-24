/*
114. Flatten Binary Tree to Linked List
Medium

Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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

//Method 1
//Store all the nodes in a vector in preorder and assign the vector values to the right of each node in tree
//and assign left as NULL 
//in place conversion from a tree to a linked list
class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*>& result){
        if(root!=NULL){
            result.push_back(root);
            preorder(root->left, result);
            preorder(root->right, result);
        }
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> result;
        if(root==NULL)
            return;
        preorder(root, result);
        for(int i=0;i<result.size()-1;i++){
            result[i]->right=result[i+1];
            result[i]->left=NULL;
        }
        result[result.size()-1]->left= result[result.size()-1]->left = NULL;
    }
};

//Method 2
/*For a subtree, we store the root's right child in a temporary variable and store root's left child in root->right
 Then we traverse to the rightmost child of the root and make that child's right as the temporary variable.
 Consider this subtree: 
   1
  / \
 2   3

We store node 3 in a temporary variable. Then we make node 2 as the right child of root node, 1
Then we go to the rightmost node from root, that is 2, and make the right node of 2 as the node in the temp variable, ie 3
*/

TreeNode* getRightMost(TreeNode* root){
        // if(root==NULL) return root;
        if(root->right==NULL) return root;
        return getRightMost(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left=NULL;
        TreeNode* rightnode = getRightMost(root);
        rightnode->right = temp;
    }
 
