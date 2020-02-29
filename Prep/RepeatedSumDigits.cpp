#include<iostream>
#include<stdlib.h>
using namespace std;

int sum_digits(int n)
{
    int sum=0;int sum2=0;
    while(n>0 || sum>9)
    {
        if(n==0)
        {
            n=sum;
            sum=0;
        }
        sum+=n%10;
        sum2=sum;
        n/=10;
    }
    return sum;
}

int main()
{
    cout<<"Sum is :  "<<sum_digits(12347);
    return 0;
}