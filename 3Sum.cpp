/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        //Avoiding the duplicates
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int beg=i+1;
            int end=n-1;
            while(beg<end)
            {
                int target = 0 - nums[i];
                if(nums[beg]+nums[end]==target)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[beg]);
                    temp.push_back(nums[end]);
                    result.push_back(temp);
                    while(beg<end && nums[beg]==nums[beg+1])
                        beg++;
                    while(beg<end && nums[end]==nums[end-1])
                        end--;
                    beg++;
                    end--;
                }
                else if(nums[beg]+nums[end]<target)
                    beg++;
                else
                    end--;
            }
            
        }
        return result;
    }
};