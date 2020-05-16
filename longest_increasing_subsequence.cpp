#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
#include <bits/stdc++.h>

using namespace std;

int longestIncreasingSubsequence(vector<int> a)
{
    if(a.size()==1)
        return 0;
    vector<int> val(a.size(), 1); //initializing all the elements as 1 since LIS for each index will be atleast 1
    int result=1;
    for(int i=1;i<a.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                val[i]=max(val[j]+1, val[i]);
            }
            if(val[i]>result)
                result=val[i];
        }
    }

    //return *max_element(val.begin(), val.end());
    return result;
}

int main()
{
    vector<int> a={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout<<"The longest increasing subsequence length is : "<<longestIncreasingSubsequence(a)<<endl;
    return 0;
}