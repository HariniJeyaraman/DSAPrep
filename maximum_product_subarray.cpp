/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]
*/
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
#include <bits/stdc++.h>

using namespace std;

// We cannot just do it in this way
//We cannot just make current product as 1 when number is negative like how we do it in kadane's (for max sum in kadane's algo, we makw
//current sum =0 when the element is -ve) because even if one element is -ve the sum will decrease and cannot be maximum.
//but for product, there is a chance that even if 1 element in -ve, the product can still be maximum 
//if there are even nuumber of -ve elements
int max(int a, int b){
    if(a>b)return a;
    else return b;
}

int min(int a, int b){
    if(a<b)return a;
    else return b;
}

int maxProduct(const vector<int> &A)
{
    int n = A.size();
    vector<int> maxarray(n);
    vector<int> minarray(n);
    maxarray[0] = A[0];
    minarray[0] = A[0];
    int result = A[0];
    for(int i=1;i<n;i++){
        if(A[i]>0){
            maxarray[i] = max(A[i],maxarray[i-1]*A[i]);
            minarray[i] = min(A[i],minarray[i-1]*A[i]);
        }else{
            maxarray[i] = max(A[i],minarray[i-1]*A[i]);
            minarray[i] = min(A[i],maxarray[i-1]*A[i]);
        }
        //result = max(result,maxarray[i]);
    }
    int cmax=maxarray[0];
    for(int i=0;i<n;i++)
    {
        if(maxarray[i]>cmax)
            cmax=maxarray[i];
        cout<<maxarray[i]<<" ";
    }
    cout<<endl;
    return cmax;
}

int main()
{
    vector<int> a={-1,-3,-10,0,60};//{-1,-3,-10,0,60};//{2, 3, -2, 4};
    cout<<"Max product is : "<<maxProduct(a)<<endl;
    return 0;
}

/*
minarray's purpose is to handle negative numbers.
When A[i] is positive, prev*A[i] doesn't change of sign. Other case to handle: when previous value is 0

So maximum product until index i is

    A[i] if maxarray[i-1] is 0 (or negative with initialization)
    maxarray[i-1]*A[i] else.

std::max simplifies the condition.

In the same way, minimum product (largest negative number) would be std::min(A[i], minarray[i-1] * A[i]).

When A[i] is negative, prev*A[i] does change of sign. so maximum has to take previous minimum

maxarray[i] = max(A[i], minarray[i-1] * A[i]);.

When A[i] == 0, both maximum and minimum would be 0. (both branch would be fine for it).
*/