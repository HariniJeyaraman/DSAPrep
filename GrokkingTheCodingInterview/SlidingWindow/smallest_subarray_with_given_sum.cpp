//Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray 
// whose sum is greater than or equal to ‘S’. 
// Return 0, if no such subarray exists.
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int lengthOfSmallestSubarray(vector<int> a, int S){
    int curSum = 0;
    int l=0;
    int result=INT16_MAX;
    for(int r=0;r<a.size();r++){
        curSum+=a[r];
        while(curSum>=S){
            result = min(result,r-l+1);
            curSum-=a[l];
            l++;
        }
    }
    return result == INT16_MAX ? 0 : result;
}

int main(){
    vector<int> a = {2,1,5,2,3,2};
    cout<<lengthOfSmallestSubarray(a,7)<<endl;
    cout<<lengthOfSmallestSubarray({2,1,5,2,8},7)<<endl;
    cout<<lengthOfSmallestSubarray({3,4,1,1,6},8)<<endl;
}