/*
Given a list of positive integers nums and an int target, return indices of the two numbers such that they add up to a target - 30.

Conditions:

    You will pick exactly 2 numbers.
    You cannot pick the same element twice.
    If you have muliple pairs, select the pair with the largest number.

Example 1:

Input: nums = [1, 10, 25, 35, 60], target = 90
Output: [2, 3]
Explanation:
nums[2] + nums[3] = 25 + 35 = 60 = 90 - 30

Example 2:

Input: nums = [20, 50, 40, 25, 30, 10], target = 90
Output: [1, 5]
Explanation:
nums[0] + nums[2] = 20 + 40 = 60 = 90 - 30
nums[1] + nums[5] = 50 + 10 = 60 = 90 - 30
You should return the pair with the largest number.
*/

#include<cstdlib>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> findSum(vector<int> nums, int target)
{
    map<int, int> mp;
    target=target-30;
    vector<int> result;
    int max1=-999, max2=-999;
    if(nums.size()<2)
        return result;
    for(int i=0;i<nums.size();i++)
    {
        if(mp.find(target-nums[i])!=mp.end())
        {
            if(i>max2 && mp[target-nums[i]]>max1)
            {
                max2=i;
                max1=mp[target-nums[i]];
                // result.push_back(i);
                // result.push_back(mp[target-nums[i]]);
            }
        }
        //We only need the bigger pair
        if(mp.find(nums[i])==mp.end())
            mp[nums[i]]=i;
    }
    result.push_back(max2);
    result.push_back(max1);
    return result;
}


int main()
{
    vector<int> nums={20, 50, 40, 25, 30, 10};
    int target=90;
    vector<int> result=findSum(nums,target);
    for(int el:result)
    cout<<el<<" ";
    cout<<endl;
    return 0;

}