/*
Problem Statement 
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target 
where i, j, and k are three different indices. Write a function to return the count of such triplets.

Example 1:

Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]

Example 2:

Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
   [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
*/
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

int tripletCountSmaller(vector<int> &a, int target){
    int count=0, n=a.size();
    sort(a.begin(), a.end());
    int left = 0, right = n-1;
    for(int i=0; i<n-2;i++){
        left=i+1;
        while(left<right){
            if(a[left]+a[right]+a[i]<target){
                count+=(right-left);
                left++;
            }
            else{
                right--;
            }
            
        }
    }
    return count;
}

int main(){
    vector<int> a = {-1, 0, 2, 3};
    cout<<tripletCountSmaller(a, 3)<<endl;
    a = {-1, 4, 2, 1, 3};
    cout<<tripletCountSmaller(a, 5)<<endl;
}