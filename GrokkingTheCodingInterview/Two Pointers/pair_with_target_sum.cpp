/*
Pair with Target Sum (easy)
Problem Statement

Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.

Example 1:

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6

Example 2:

Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
using namespace std;

pair<int, int> TwoSum(vector<int> a, int sum){
    int l = 0, r = a.size()-1;
    while(l<r){
        if(a[l]+a[r]==sum)
            return make_pair(l,r);

        if(a[l]+a[r]>sum){
            r--;
        }
        else{
            l++;
        }
        
    }
    return make_pair(-1,-1);
}

pair<int, int> TwoSum2(vector<int> a, int sum){
    unordered_map<int, int> m;
    for(int i=0;i<a.size();i++){
        if(m.find(sum-a[i])!=m.end()){
            return make_pair(m[sum-a[i]], i);
        }
        else
            m[a[i]] = i;
    }
    return make_pair(-1,-1);
}

int main(){
    
    cout<<TwoSum({1, 2, 3, 4, 6},6).first<<" "<<TwoSum({1, 2, 3, 4, 6},6).second<<endl;
    cout<<TwoSum({2, 5, 9, 11},11).first<<" "<<TwoSum({2, 5, 9, 11},11).second<<endl;

    cout<<TwoSum2({1, 2, 3, 4, 6},6).first<<" "<<TwoSum({1, 2, 3, 4, 6},6).second<<endl;
    cout<<TwoSum2({2, 5, 9, 11},11).first<<" "<<TwoSum({2, 5, 9, 11},11).second<<endl;
    return 0;
}