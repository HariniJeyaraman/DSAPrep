/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>

using namespace std;

//Lame method using hashmap O(N) space and time complexity
int singleNumber_lame_method(vector<int> A)
{
    map<int, int> freq;
    for(int i=0;i<A.size();i++)
    {
        freq[A[i]]++;
    }
    
    map<int, int>::iterator it;
    for(it=freq.begin();it!=freq.end();it++)
    {
        if(it->second==1)
            return it->first;
    }
    return -1;
}

//Constant Space and O(N) time. NOTE : The outer loop runs for a constant number of times(32)
//The idea is to count the number of set bits in each position for all the numbers in the vector. If it is a multiple of 3
//set the result in that position to 0, else set it to 1.
int singleNumber_better_method(vector<int> A)
{
     int result=0;
    for(int i=0;i<32;i++)
    {
        int count=0;
        for(int j=0;j<A.size();j++)
        {
            if((A[j] & (1 << i))!=0)
                count++;
        }
        result=result|((count%3)<<i);
    }
    return result;
}

int main()
{
    vector<int> a={1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
    cout<<"Single number is : "<<singleNumber_lame_method(a)<<endl;
    cout<<"Single number is : "<<singleNumber_better_method(a)<<endl;
    return 0;
}