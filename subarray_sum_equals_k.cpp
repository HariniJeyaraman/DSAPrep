/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

 

Constraints:

    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

//we are calculating cumulative sum. The sum of a subarray from index i to j will be cumulative sum at j - cumulative sum at i.
//We use this concept and check for a subarray of sum k
//CumSumCurrent - CumSumPrev should be equal to k
//We need to look in the map if such a CumSumPrev exists.
//CumSumCurrent - CumSumPrev = k
//=> CumSumPrev = CumSumCurrent - k
//We search for such a CumSumPrev in the map. If it exists, then we have a subarray of sum k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        map<int,int> c;
        c[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(c[sum-k]>0)
                ans+=c[sum-k];
            c[sum]++;
        }
        return ans;
    }
};