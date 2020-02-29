//Number of occurrences of 2 as a digit in numbers from 0 to n
#include<iostream>
#include<stdlib.h>
using namespace std;

int occurences_two(int n)
{
    int count=0;
    for(int i=0;i<=n;i++)
    {
        int i_temp=i;
        while(i_temp>0)
        {
            int d=i_temp%10;
            if(d==2)
            {
                count++;
            }
            i_temp/=10;
        }
    }
    return count;
}

int main()
{
    int z = occurences_two(100);
    cout<<"Number of occurences of 2 from o to n is : "<<z;
}