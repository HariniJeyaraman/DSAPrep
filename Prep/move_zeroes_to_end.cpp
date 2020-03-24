#include<stdlib.h>
#include<iostream>
using namespace std;

void move_zeroes(int arr[], int a[], int n)
{
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 0)
        {
            arr[k] = a[i];
            k++;
        }
           
    }
    for(int i = k; i < n; i++)
    {
        arr[i] = 0;
    }    

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<"\t";
}

int main()
{
    int n;
    cout<<"Enter the size of array : \n";
    cin>>n;
    int a[n],arr[n];
    cout<<"Enter the values for the array : \n";
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    move_zeroes(arr, a, n);
    return 0;
}