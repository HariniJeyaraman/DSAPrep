/*
Remove Element

Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

    Example:
    If array A is [4, 1, 1, 2, 1, 3]
    and value elem is 1,
    then new length is 3, and A is now [4, 2, 3] 

Try to do it in less than linear additional space complexity.
*/
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int removeElement(vector<int> &A, int B)
{
    int n=A.size();
    int count=0,c=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]!=B)
        {
            A[count]=A[i];
            count++;
        }
        else
        c++;
    }
    for(int i=0;i<c;i++)
        A.pop_back();
    for(int el : A)
        cout<<el<<" ";
    cout<<endl;
    return count;
}

int main()
{
    vector<int> a={4, 1, 1, 2, 1, 3};
    cout<<"The number of elements after removing is : "<<removeElement(a,1)<<endl;
    return 0;
}