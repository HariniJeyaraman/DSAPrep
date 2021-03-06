/*
448. Find All Numbers Disappeared in an Array
Easy

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> result;
        if(nums.size()==0)
            return result;
        for(int i=0;i<nums.size();i++)
        {
                s.insert(nums[i]);
        }
        
        for(int i=1;i<=nums.size();i++)
        {
            if(s.find(i)==s.end())
                result.push_back(i);
        }
        return result;
    }
};