#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

void even_odd(int a[], int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while(a[i]%2==0 && i<j)
            i++;
        while(a[j]%2!=0 && i<j)
            j--;
        if(i<j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
        
    }
}

int main()
{
    int a[]={12,33,5,8,9,15,6,20};
    int n = sizeof(a)/sizeof(a[0]);
    even_odd(a,n);
    cout<<"After segregation : \n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}