/*
Problem Statement #
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

Example 1:

Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.
Example 2:

Input: [-3, -1, 1, 2], target=1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.
Example 3:

Input: [1, 0, 1, 1], target=100
Output: 3
Explanation: The triplet [1, 1, 1] has the closest sum to the target.
*/
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

int tripletSumClose(vector<int> a, int target){
    sort(a.begin(),a.end());
    int left,right,minDiff,result=INT16_MAX;
    for(int i=0;i<a.size()-2;i++){
        left = i+1, right = a.size()-1;
        while(left<right){
            minDiff = (target-a[i]-a[left]-a[right]);
            if(minDiff == 0) return a[i]+a[left]+a[right];
            if(abs(minDiff)<abs(result)) result = minDiff;
            if(minDiff > 0) left++;
            else right--;
        }
    }
    return target - result;
}

int main(){
    cout<<tripletSumClose({-2,0,1,2}, 2)<<endl;
    cout<<tripletSumClose({-3,-1,1,2}, 1)<<endl;
    cout<<tripletSumClose({1,0,1,1}, 100)<<endl;
    return 0;
}
