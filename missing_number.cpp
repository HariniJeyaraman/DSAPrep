/*
268. Missing Number
Easy

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2

Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int expectedSum = n*(n+1)/2;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        return expectedSum - sum;
        
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[nums.size()-1] != nums.size()) {
            return nums.size();
        }
        // Ensure that 0 is at the first index
        else if (nums[0] != 0) {
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i)
                continue;
            else
                return nums[i]-1;
        }
        return -1;     
    }
};