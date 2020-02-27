//Finding the 2nd largest element in an array
#include<iostream>
#include<stdlib.h>
#include<array>
using namespace std;

int main()
{
    int a[]={1,3,2,5,111,32,51,67};
    int max_first=-666;
    int max_second=-666;
    int len = sizeof(a)/sizeof(a[0]);
    if(len<2)
    cout<<"Cannot find 2nd greatest element. Need atleast 2 elements in the array\n";
    for(int i=0;i<len;i++)
    {
        if(a[i]>max_first)
        {
            max_second=max_first;
            max_first=a[i];
        }

        else if(a[i]>max_second && a[i]!=max_first)
        {
            max_second=a[i];
        }
    }
    if(max_second==-666)
    cout<<"There is no 2nd greatest";
    else
    cout<<"The 2nd greatest element is :  "<<max_second<<"\n";
    return 0;
}