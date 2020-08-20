/*
287. Find the Duplicate Number
Medium

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2

Example 2:

Input: [3,1,3,4,2]
Output: 3

Note:

    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.

*/
//Using map
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        if(nums.size()==0)
            return 0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>1)
                return nums[i];
        }
        return 0;
    }
};

//Floyd's Tortoise and Hare (Cycle Detection)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

       

        int slow=nums[0];
        int fast=nums[0];
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)
                break;
        }
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};