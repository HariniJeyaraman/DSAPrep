/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<cmath>

int majorityElement(std::vector<int>& nums) {
        std::map<int, int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        std::map<int, int>:: iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second > floor((nums.size())/2))
                return it->first;
        }
        return -1;
    }

int main()
{
    std::vector<int> a={2, 2, 1, 1, 1, 2, 2};
    std::cout<<"Majority element is : "<<majorityElement(a)<<std::endl;
    return 0;
}