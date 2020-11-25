/*
Problem Statement #
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.
Example 2:

Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.
*/

#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> TripletSumZero(vector<int> a){
    sort(a.begin(), a.end());
    vector<vector<int>> result;
    for(int i=0;i<a.size()-2;i++){
        if(i>0 && a[i] == a[i-1]) continue;  //skip same element to avoid duplicate triplets
        int left = i+1, right = a.size()-1;
        while(left<right){
            if(a[left]+a[right]+a[i]==0){
                result.push_back({a[i], a[left], a[right]});
                left++; right--;
                while(left<right && a[left] == a[left-1]) left++;     //skip same element to avoid duplicate triplets
                while(left<right && a[right] == a[right+1]) right--;  //skip same element to avoid duplicate triplets
            }
            else if(a[left]+a[right] > -1*a[i])
                right--;
            else left++;
        }
    }
    return result;
}

int main(){
    vector<vector<int>> res;
    res = TripletSumZero({-5,2,-1,-2,3});
    for(auto el : res) {
        for(int val : el){
            cout<<val << " ";
        }
        cout<<endl;
    }

    res = TripletSumZero({-3,0,1,2,-1,1,-2});
    for(auto el : res) {
        for(int val : el){
            cout<<val << " ";
        }
        cout<<endl;
    }

    return 0;
}