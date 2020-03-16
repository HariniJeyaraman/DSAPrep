//Segregate positive and negative numbers in an array
// Here, we try to place all negative numbers to the left 
//and all positive elements to the right in O(n) time.
//We can achieve this using Sorting also. But that takes O(nlogn) time.
#include<iostream>
#include<stdlib.h>
using namespace std;

//Similar to the partition function in Quicksort
//with pivot as 0
void segregate_pos_neg(int a[],int n)
{
    int left = 0;
    int right = n-1;
    while(1)
    {
        while(a[left]<0 && left<right)
            left++;
        while(a[right]>0 && left<right)
            right--;
        if(left<right)
        {
            int temp=a[left];
            a[left]=a[right];
            a[right]=temp;
        }     
        else 
            break;  
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array";
    cin>>n;
    //allocating heap memory for array
	int *a = new int[n];
    cout<<"Enter the values of the array\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    segregate_pos_neg(a,n);
    cout<<"Array after partition function\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}