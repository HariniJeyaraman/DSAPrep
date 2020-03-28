//Fisher–Yates shuffle Algorithm  to shuffle array 
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void shuffle(int a[], int n)
{
    srand(time(NULL));
    for(int i=1;i<n;i++)
    {
        int j=rand()%i;
        swap(a[i],a[j]);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

    int main()
    {
        int a[]={1, 2, 3, 4, 5, 6, 7, 8};
        int n=sizeof(a)/sizeof(a[0]);
        shuffle(a,n);
        return 0;
    }
