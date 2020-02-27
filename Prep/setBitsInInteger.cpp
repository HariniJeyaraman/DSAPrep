#include<stdio.h>
#include<iostream>
using namespace std;

int set_bits_count(int n)
{
    int count=0;
    while(n)
    {
        count+=n&1;
        n=n>>1;
    }
    return count;
}

int main()
{
    int c = set_bits_count(15);
    cout<<c<<"\n";
}