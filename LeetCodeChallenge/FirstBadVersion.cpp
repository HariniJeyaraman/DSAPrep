//Leetcode May Challenge
//May 4th
/*
You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version.
*/
#include<iostream>
#include<cstdlib>
#include<vector>

//bool isBadVersion(int version) is already defined

//This problem is similar to finding the 1st 1 in an array of 0's and 1's where the array is sorted.
//We use the concept of Binary Search to minimize the number of calls to the API isBadVersion
int firstBadVersion(int n)
{
    int beg=1;
    int end=n;
    while(beg<=end)
    {
        int mid=beg+(end-beg)/2;
        if(!isBadVersion(mid))
        {
            beg=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return beg;
}

//Let us implement the problem where you are given a sorted array of 0's and 1's and you need to find occurence of the first 1.
int firstOne(std::vector<int> a)
{
    int beg=0;
    int end=a.size()-1;
    while(beg<=end)
    {
        int mid=beg+(end-beg)/2;
        if(a[mid]==0)
            beg=mid+1;
        else
            end=mid-1;
    }
    return beg;
}

int main()
{
    std::vector<int> a={0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    std::cout<<"The index of 1st one is : "<<firstOne(a)<<"\n";
    return 0;
}