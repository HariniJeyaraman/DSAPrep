/*
209. Minimum Size Subarray Sum
Medium

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
*/

//O(n^2) solution
class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int sum=0, minLength=INT_MAX;
        if(nums.size()==0)
            return 0;
       for(int i=0;i<nums.size();i++){
           sum=0;
           for(int j=i;j<nums.size();j++){
               sum+=nums[j];
               if(sum>=k){
                   minLength=min(minLength,j-i+1);
                   break;
               }
           }
       }
        return (minLength==INT_MAX)?0:minLength;
    }
};

//O(n) solution usng sliding window method
class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int left=0, sum=0,minLen=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=k){
                minLen=min(minLen,i-left+1);
                sum=sum-nums[left];
                left++;
            }
        }
        return minLen==INT_MAX?0:minLen;
    }
};