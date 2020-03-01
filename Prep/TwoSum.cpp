//You're tasked with figuring out the pair of elements where arr[p] + arr[q] add up to a certain number
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

//O(n^2) Solution
vector<int> TwoSum(vector<int>& num,int target)
{
    vector<int> result;
    for(int i=0;i<num.size();i++)
    {
        for(int j=i+1;j<num.size();j++)
        {
            if(num[i]+num[j]==target)
            {
                result.push_back(i);
                result.push_back(j);
                
            }
        }
    }
    return result;
}

//O(n) Solution if we are given a sorted array otherwise we need to sort the array first => O(n^2) complexity
//Using 2 pointers
vector<int> TwoSum_better(vector<int> &num,int target)
{
    //we are given a sorted array
    int left = 0;
    int sum=0;
    int right = num.size()-1;
    vector<int> result;
   // for(int i=0;i<num.size()-1;i++)
   while(left<right)
    {
        sum=num[left]+num[right];
        if(sum==target)
        {
            result.push_back(left);
            result.push_back(right);
        }
        if(sum<target)
            left++;
        else 
            right--;

    }
    return result;
}

int main()
{ //0,1,2,4,7,10
    vector<int> res;
    vector<int> res_two_pointer;
    vector<int> res_brute_force;
    res.push_back(0);
    res.push_back(1);
    res.push_back(2);
    res.push_back(4);
    res.push_back(7);
    res.push_back(10);
    res_two_pointer=TwoSum_better(res,9);
    cout<<"Indices using 2 pointer are : ";
    for(int i=0;i<res_two_pointer.size();i++)
    {
        cout<<res_two_pointer[i]<<"\t";
    }
    cout<<"\nIndices using brute force are : ";
    res_brute_force=TwoSum(res,9);
    for(int i=0;i<res_brute_force.size();i++)
    {
        cout<<res_brute_force[i]<<"\t";
    }
}