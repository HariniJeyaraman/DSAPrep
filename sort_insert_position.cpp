/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be
if it were inserted in order.

You may assume no duplicates in the array.
*/

#include<iostream>
#include<cstdlib>
#include<vector>
//Basically same as Binary Search Implementation. Only tweak we need to do is after the while loop is over, we need to return the value of beg instead of -1

int insert_position(std::vector<int> a, int target)
{
    int beg=0,end=a.size()-1;
    while(beg<=end)
    {
        int mid=(beg+end)/2;
            if(a[mid]==target)
                return mid;
            if(a[mid]<target)
                beg=mid+1;
            else
                end=mid-1;
        
    }
    return beg;
}

int lame_method_to_do_the_same(std::vector<int> nums, int target)
{
    int beg=0,end=nums.size()-1;
        int mid;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
            {
                beg=mid+1;
            }
            else
                end=mid-1;
        }
        if(mid+1 < nums.size() && target>nums[mid] && target<nums[mid+1])
            return mid+1;
        if(mid==nums.size()-1 && target > nums[mid])
            return mid+1;
        return mid;
}
int main()
{
    std::vector<int> a={1,3,5,6};
    std::cout<<"Position : "<<insert_position(a,7)<<"\n";
    std::cout<<"Position : "<<lame_method_to_do_the_same(a,7)<<"\n";
}