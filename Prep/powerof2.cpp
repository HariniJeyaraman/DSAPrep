#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

int powerOf2(int n)
{
    if(n==0)
    return 0;
    return (ceil(log2(n)==floor(log2(n))));
}
int main()
{
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    if(powerOf2(n))
        cout<<"Number given is a power of 2\n";
    else
        cout<<"Number not a power of 2\n";
    return 0;    
}