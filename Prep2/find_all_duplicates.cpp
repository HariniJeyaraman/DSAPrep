/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array)
find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
*/

#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> find_duplicates(std::vector<int> A)
{
    std::vector<int> duplicates;
    for(int i=0;i<A.size();++i)
    {
        int index = abs(A[i])-1;
        if(A[index]<0)
        {
            duplicates.push_back(index+1);
        }
        A[index]=-A[index];

    }
    return duplicates;
}

int main()
{
    int n;
    std::cout<<"Enter the size of the array :\n";
    std::cin>>n;
    std::vector<int> A(n);
    std::cout<<"Enter the value of the elements of the array (1 ≤ a[i] ≤ n) : \n";
    for(int i=0;i<n;++i)
    {
        std::cin>>A[i];
    }
    std::cout<<"The duplicates of the array are :  ";
    std::vector<int> result(n);
    result = find_duplicates(A);
    for(int val : result)
        std::cout<<val<<" ";
    std::cout<<"\n";
    return 0;
}