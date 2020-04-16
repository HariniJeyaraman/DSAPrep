#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main(void){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=1;i<n/2;i++)
    {
        for(int j=i;j<=n-i-2;j=j+2)
        {
            swap(a[j],a[j+1]);
        }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
