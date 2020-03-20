//QuickSort implementation
#include<stdlib.h>
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int partition(int a[], int beg, int end)
{
    int i = beg;
    int j = end;
    int pivot = a[beg];
    while(i < j)
    {
        while(a[i] <= pivot && i < end)
            i++;
        while(a[j] > pivot && j > beg)
            j--;
        if(i < j)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[beg],a[j]);
    return j;
}

void QuickSort(int a[], int beg, int end)
{
    if(beg < end)
    {
        int j = partition(a, beg, end);
        QuickSort(a, beg, j-1);
        QuickSort(a, j+1, end);
    }
}

int main()
{
    int a[] = {12, 3, 20, 7, 9, 6, 34, 5, 2, 10};
    int n = sizeof(a)/sizeof(a[0]);
    QuickSort(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
}