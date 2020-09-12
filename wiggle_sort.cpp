/*
280. Wiggle Sort
Medium

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 0)
            return;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i%2 == 0) {
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                    }
                } 
            else {
                if (nums[i] < nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
    }
};