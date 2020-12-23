/*
35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Example 4:
Input: nums = [1,3,5,6], target = 0
Output: 0

Example 5:
Input: nums = [1], target = 0
Output: 0
*/
class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        for(int i=0;i<a.size();i++){
        if(a[i] == target) 
            return i; //Found a match
        else if(a[i] > target) 
            return i; //Target should be inserted here
    }
    return a.size(); //Insert at last position of vector if all elements are lesser than target
    }
};