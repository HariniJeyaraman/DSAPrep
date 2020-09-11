/*
259. 3Sum Smaller
Medium

Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Follow up: Could you solve it in O(n2) runtime?

 

Example 1:

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]
Example 2:

Input: nums = [], target = 0
Output: 0
Example 3:

Input: nums = [0], target = 0
Output: 0
 

Constraints:

n == nums.length
0 <= n <= 300
-100 <= nums[i] <= 100
-100 <= target <= 100
*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int c=0,f=0;
        for(int i=0;i<nums.size()-2;i++){
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int sum = target-nums[i];
                if(nums[l]+nums[r]<sum){
                   c+=(r-l);//accomodating all combinations with sum<target between start and end
                    l++;
                }
               
                if(nums[l]+nums[r]>=sum)
                {
                    r--;
                }
            }
        }
        return c;
    }
};

