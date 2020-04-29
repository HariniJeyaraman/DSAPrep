/*
Given an array arr[0 .. n-1] of distinct integers, the task is to find a local minima in it. 
We say that an element arr[x] is a local minimum if it is less than or equal to both its neighbors.

    For corner elements, we need to consider only one neighbor for comparison.
    There can be more than one local minima in an array, we need to find any one of them.

*/
#include<iostream>
#include<cstdlib>
#include<vector>

//O(n) solution by performing linear scan of elements
int localMinima_naive(std::vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        if(i>=1 && a[i]<a[i+1] && a[i]<a[i-1])
            return a[i];
        if((i==0 && a[i]<a[i+1]) || (i==a.size()-1 && a[i]<a[i-1]) )
            return a[i];
    }
    return -1;
}

int localMinima(std::vector<int> a)
{
    int beg=0;
    int end=a.size()-1;
    while(beg<=end)
    {
        int mid=beg+(end-beg)/2;
        if((mid==0 && a[mid]<a[mid+1]) || (mid==a.size()-1 && a[mid]<a[mid-1]) || (mid>0 && a[mid]<a[mid-1] && a[mid]<a[mid+1]) )
            return a[mid];
        // If middle element is not minima and its left 
        // neighbour is smaller than it, then left half 
        // must have a local minima. 
        else if(mid>0 && a[mid]>a[mid-1])
            end=mid-1;
        // If middle element is not minima and its right 
        // neighbour is smaller than it, then right half 
        // must have a local minima. 
        else
            beg=mid+1;
    }
    return -1;
}

int main()
{
    std::vector<int> a={7, 0, 1, 3, 2, 4, 8, 6, 12, 14, 19, 11, 16, 30};
    std::cout<<"Local minima is : "<<localMinima_naive(a)<<"\n";
    std::cout<<"Local minima is : "<<localMinima(a)<<"\n";
    return 0;
}