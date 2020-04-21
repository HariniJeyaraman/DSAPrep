/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
*/
#include<iostream>
#include<cstdlib>
#include<vector>

int removeDuplicates(std::vector<int> a)
{
    int result,index=1;
    for(int i =0;i<a.size()-1;i++) //index is initialized to 1 since index 0 (first element will always be unique)
    {
        if(a[i]!=a[i+1])
        {
            a[index++]=a[i+1];
            // index++;
        }
    }
    a.erase(a.begin()+index,a.end()); //removing the duplicate elements
    for(int i : a)
    std::cout<<i<<" ";
    std::cout<<"\n";
    return index;
}

int main()
{
    std::vector<int> a={1,1,2,2,3,5};
    std::cout<<removeDuplicates(a)<<"\n";
    return 0;
}