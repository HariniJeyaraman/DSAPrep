#include<iostream>
#include<cstring>
#include<cstdlib>
#include<queue>

using namespace std;
//mcss
/*
int main(){
    int n = 6;
    int a[] = {2,-5,21,-7,8,6};
    // int csum = 0, result = INT16_MIN;
    // for(int i=0;i<n;i++){
    //     csum+=a[i];
    //     if(csum<0) csum = 0;
    //     result = max(csum,result);
    // }
    // cout<<result<<endl;
    //max increasing subsequence
    int dp[]={1,1,1,1,1,1};
    int result = INT8_MIN;
    for(int i=0;i<n;i++){
        for(int j = 0;j < i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[j]+1, dp[i]);
            }
            if(dp[i]>result) result = dp[i];
        }
    }
    cout<<result<<endl;
}
*/
/*
int bsearch(int* a, int beg, int end, int key){
    int mid=(beg+end)/2;
    if(key == a[mid]) return mid;
    else if(a[mid]<key) bsearch(a,mid+1,end,key);
    else bsearch(a,beg,mid,key);
    return -1;
}

int main(){
    int a[] = {1,4,2,7,6,9,8};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<bsearch(a,0,n-1,7)<<endl;
    return 0;
}*/

struct node{
    int val;
    node* right;
    node* left;
};

void inorder(node* root){
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}

node* insert(node* root, int val){
    node* new_node = new node();
    new_node->val = val;
    new_node->left= NULL;
    new_node->right = NULL;
    if(root == NULL){
        root = new_node;
    }
    else if(new_node->val > root->val){
        root->right = insert(root->right, val);
    }
    else if(new_node->val <= root->val){
        root->left = insert(root->left, val);
    }
    return root;
}

void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* cur = q.front();
        cout<<cur->val;
        q.pop();
        if(cur->left!=NULL)
        q.push(cur->left);
        if(cur->right!=NULL)
        q.push(cur->right);
    }
}

int main(){
    node* root = new node();
    root = NULL;
    node* r = insert(root, 3);
    inorder(r);
    r = insert(r, 1);
    inorder(r);
    r = insert(r, 2);
    inorder(r);
    r = insert(r, 5);
    inorder(r);
    r = insert(r, 6);
    inorder(r);
    r = insert(r, 4);
    inorder(r);
    levelOrder(r);
    
}