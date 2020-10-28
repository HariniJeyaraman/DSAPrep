/*
Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.
*/
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

//Using Sliding Window concept

int maxSubarraySumk(vector<int> a, int k){
    int cumSum=0, left=0, right=k-1;
    for(int i=left; i<=right; i++){
        cumSum+=a[i];
    }
    right++;
    int result=cumSum;
    while(right<a.size()){
        cumSum+=a[right];
        cumSum-=a[left];
        result=max(result, cumSum);
        left++;
        right++;
    }
    return result;
}

int main(){
    vector<int> a={2,1,5,1,3,2};
    cout<<maxSubarraySumk(a,3)<<endl;
    vector<int> b = {2,3,4,1,5};
    cout<<maxSubarraySumk(b,2);
    return 0;
}