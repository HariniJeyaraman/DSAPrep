/*
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2

Output :

1
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
using namespace std;

int diffk(vector<int> a, int k)
{
    map<int, int> m;
    for(int i=0;i<a.size();i++)
    {
        if(m.find(a[i]+k)!=m.end() || m.find(a[i]-k)!=m.end())
            return 1;
        if(m.find(a[i])==m.end())
            m[a[i]]=i;
    }
    return 0;
}

int main()
{
    vector<int> a={1, 5, 3};
    cout<<"Result is : "<<diffk(a,2)<<endl;
    return 0;
}