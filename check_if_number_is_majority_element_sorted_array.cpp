/*
1150. Check If a Number Is Majority Element in a Sorted Array
Easy

Given an array nums sorted in non-decreasing order, and a number target, return True if and only if target is a majority element.

A majority element is an element that appears more than N/2 times in an array of length N.

 

Example 1:

Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: 
The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.
Example 2:

Input: nums = [10,100,101,101], target = 101
Output: false
Explanation: 
The value 101 appears 2 times and the length of the array is 4.
Thus, 101 is not a majority element because 2 > 4/2 is false.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 10^9
1 <= target <= 10^9
*/

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        if(nums.size()==0)
            return false;
        int beg=0,end=nums.size()-1;
        int mid,c=0,f=0;
        while(beg<=end){
            mid = beg + (end-beg)/2; //integer overflow
            if(nums[mid]==target){
                f=1;
                break;
            }
            else if(nums[mid]<target)
                beg=mid+1;
            else
                end=mid-1;    
        }
        if(f==1){
            for(int r = mid;r<nums.size();r++){
            if(nums[r]==target)
                c++;
            else
                break;
        }
       for(int l = mid-1;l>=0;l--){
        if(nums[l]==target)
            c++;
        else
            break;
        }
            if(c>nums.size()/2)
            return true;
        // return false;
        }
        
        return false;
        
    }
};