/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/

//Very long, lame and unnecessary code, but it works ! Not ideal
class Solution {
public:
    int binarySearch(vector<int> &nums, int target)
    {
        int beg=0;
        int end=nums.size()-1;
        while(beg<=end)
        {
            int mid=beg+(end-beg)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else
                beg=mid+1;
                
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
       int pos=binarySearch(nums, target);
        vector<int> result={-1,-1};
        if(nums.size()==1 && pos!=-1)
        {
            result[0]=pos;
            result[1]=pos;
            return result;
        }
       
        if(pos==-1)
            return result;
        
        {if(pos==0)
            result[0]=0;
        if(pos==nums.size()-1)
            result[1]=nums.size()-1;
        }
        {
        if(pos-1>0 && nums[pos-1]!=target)
            result[0]=pos;
        if(pos+1<nums.size() && nums[pos+1]!=target)
            result[1]=pos;
        //searching in the array to the left of pos
        int i;
        for(i=pos-1;i>=0;i--)
        {
            if(nums[i]==target)
                continue;
            else
                break;
                
        }
        result[0]=(i+1);
        
        //searching in the array to the right of pos
        int j;
        for(j=pos+1;j<nums.size();j++)
        {
            if(nums[j]==target)
                continue;
            else
                break;
        }
        result[1]=(j-1);
        }
        return result;
    }
};

//Better way would to be to use Binary Search to find the 1st occurence of the target element, last occurence of the target
public:
    int findStartIndex(vector<int> &nums, int target)
    {
        int beg=0;
        int index=-1;
        int end=nums.size()-1;
        while(beg<=end)
        {
            int mid=beg+(end-beg)/2;
            if(nums[mid]>=target)
            {
                end=mid-1;
            }
            
            else
                beg=mid+1;
            
            if(nums[mid]==target)
                index=mid;
            
        }
        return index;
        
    }
    
    int findEndIndex(vector<int> &nums, int target)
    {
         int beg=0;
        int index=-1;
        int end=nums.size()-1;
        while(beg<=end)
        {
            int mid=beg+(end-beg)/2;
            if(nums[mid]<=target)
            {
                beg=mid+1;
            }
            
             else
                end=mid-1;
            
            if(nums[mid]==target)
                index=mid;
           
        }
        return index;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        result[0]=findStartIndex(nums,target);
        result[1]=findEndIndex(nums,target);
        return result;
    }
};