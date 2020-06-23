/*
18. 4Sum
Medium

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                int beg = j+1;
                int end = n-1;
                int targetSum = target - nums[i] - nums[j];
                while(beg<end)
                {
                    if(nums[beg] + nums[end] == targetSum)
                    {
                        vector<int> temp={nums[i], nums[j], nums[beg], nums[end]};
                        result.push_back(temp);
                        while(beg<end && nums[beg] == nums[beg+1])
                            beg++;
                        while(beg<end && nums[end] == nums[end-1])
                            end--;
                        beg++;
                        end--;
                    }
                    else if(nums[beg] + nums[end] < targetSum)
                        beg++;
                    else
                        end--;
                    
                }
            }
        }
        return result;
        
    }
};