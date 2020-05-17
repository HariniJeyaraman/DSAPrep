/*
Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

    Example:

    Input : 

    A : [1 3 5] 
    k : 4

    Output : YES

    as 5 - 1 = 4 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.
*/
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int diffPossible(vector<int> a, int diff)
{
    int i=0, j=1;
    while(i<a.size() && j<a.size())
    {
        if(i!=j && a[j]-a[i]==diff) //a[j]-a[i] because the vector is sorted, so the next element will be greater than previous element
            return 1;
        else if(a[j]-a[i]<diff)
            j++;
        else
            i++;
        
    }
    return 0; //could not find any pair whose difference is diff
}

int main()
{
    vector<int> a={1, 3, 5};
    int res=diffPossible(a,4);
    if(res)
        cout<<"Possible ! Found 2 elements whose difference is same as target diff !\n";
    else
        cout<<"Not possible\n";
    return 0;
}