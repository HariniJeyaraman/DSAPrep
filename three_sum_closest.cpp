/*
16. 3Sum Closest
Medium

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

//Same as 3 sum but adding a condition abs(target-sum)<abs(min) so that we find the closest sum to the target (diff should be min)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min=INT_MAX;
        int result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int beg=i+1;
            int end=nums.size()-1;
            while(beg<end)
            {
                int sum=nums[i]+nums[beg]+nums[end];
                if(abs(target-sum)<abs(min))
                {
                    result=sum;
                    min=target-sum;
                }
                else if(sum<target)
                    beg++;
                 else if(sum==target)
                    return sum;
                else
                    end--;
            }
        }
        return result;
    }
};