/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
        int start=-1, end=-1;
        int n =nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                start=i;
                break;
            }
        }
        
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]<nums[i-1])
            {
                end=i;
                break;
            }
        }
       if(start==-1 || end==-1) //whole array is sorted ! so no unsorted subarray is present to sort
            return 0;
        
        int max=*max_element(nums.begin()+start, nums.begin()+end+1);
        int min=*min_element(nums.begin()+start, nums.begin()+end+1);
       // int max = nums[start], min = nums[start]; 
       //  for(int i = start + 1; i <= end; i++) 
       //  { 
       //      if(nums[i] > max) 
       //      max = nums[i]; 
       //      if(nums[i] < min) 
       //      min = nums[i]; 
       //  } 
        for(int i=0;i<start;i++)
        {
            if(nums[i]>min)
            {
                start=i;
                break;
            }
        }
        for(int i=n-1;i>end;i--)
        {
            if(nums[i]<max)
            {
                end=i;
                break;
            }
        }
        return end-start+1;
    }

int main()
{
    vector<int> nums={2,3,3,2,4};
    cout<<"The shortest unsorted continuos subarray length is : "<<findUnsortedSubarray(nums)<<endl;
    return 0;
}