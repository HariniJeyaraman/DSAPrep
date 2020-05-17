/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

*/

#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>

int rob(std::vector<int>& nums) {
        int dp[nums.size()];//max amout of money we can rob upto ith house
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return std::max(nums[0],nums[1]);
        dp[0]=nums[0];
        dp[1]=std::max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=std::max(nums[i]+dp[i-2], dp[i-1]);
        }
    return dp[nums.size()-1];
    }

int main()
{
    std::vector<int> a={2,7,9,3,1};
    std::cout<<"The maximum profit is : "<<rob(a)<<"\n";
    return 0;
}