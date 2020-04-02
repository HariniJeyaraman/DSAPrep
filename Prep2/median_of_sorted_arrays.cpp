//Finding the median of 2 sorted arrays of the same size
#include<cstdlib>
#include<iostream>
using namespace std;
// Using brute force 
//By merging both sorted arrays into 1 sorted array and finding median
// O(n) time 

void find_median(int arr1[], int arr2[], int n)
{
    int arr[n];
    int left1=0;
    int left2=0;
    int ind=0;
    while(left1<n && left2<n)
    {
        if(arr1[left1]<=arr2[left2])
        {
            arr[ind]=arr1[left1];
            left1++;
            ind++;
        }
        else
        {
            arr[ind]=arr2[left2];
            left2++;
            ind++;
        }
    }
    
    while(left1<n)
    {
            arr[ind]=arr1[left1];
            ind++;
            left1++;
    }

    while(left2<n)
    {
            arr[ind]=arr2[left2];
            ind++;
            left2++;
    }

    cout<<"Merged array is : \n";
    for(int i=0;i<2*n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    //since size of merged array will be even
    cout<<"Median of the sorted arrays of same size : "<<(float)(arr[n-1]+arr[n])/2<<"\n";

}

int main()
{
    int arr1[]={12,16,20,33,45};
    int arr2[]={19,24,55,57,60};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    find_median(arr1,arr2,n);
    return 0;
}


