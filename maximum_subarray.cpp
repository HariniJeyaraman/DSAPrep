/*
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int current_sum=nums[0], max_sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            current_sum=max(nums[i], nums[i]+current_sum);
           
            if(current_sum>max_sum)
                max_sum=current_sum;

        }
        return max_sum;
    }
};