/*Given an array arr[] of N integers where N is even, 
the task is to group the array elements in the pairs 
(X1, Y1), (X2, Y2), (X3, Y3), … 
such that the sum min(X1, Y1) + min(X2, Y2) + min(X3, Y3) + … 
is maximum.*/
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

int max_sum(int a[],int n)
{
    sort(a,a+n);
    int sum = 0;
    //For the sum of the min element in each pair to be max,
    //Start making pairs of every two 
    // consecutive elements as n is even 
    //So, (a[0],a[1]) , (a[2],a[3]) ,.... are the pairs. So, sum of min 
    //From the pairs will be sum of alterative terms of the sorted array
    for(int i = 0; i < n - 1; i += 2)
    {
        sum+=a[i];
    }
    return sum;
}
int main()
{
    int n;
    //allocating heap memory for array
	int *a = new int[n];
    cout<<"Enter the size of the array (even number of elements) : ";
    cin>>n;
    cout<<"Enter the values of the elements\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int result = max_sum(a,n);
    cout<<"Max sum of min of pairs is : "<<result;
}