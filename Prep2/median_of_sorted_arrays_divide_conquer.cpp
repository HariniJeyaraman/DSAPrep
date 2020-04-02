//Finding the median of 2 sorted arrays of the same size
#include<cstdlib>
#include<iostream>
using namespace std;
//O(logn)
// A divide and conquer based  
// efficient solution to find  
// median of two sorted arrays  
// of same size. 
int median(int arr[],int n)
{
    if(n%2==0)
        return (arr[(n/2)-1]+arr[n/2])/2;
    return arr[n/2];
}

int median_sorted_arrays(int arr1[], int arr2[], int n)
{
    if(n==1)
    {
        return (arr1[0]+arr2[0])/2;
    }
    if(n==2)
    {
        return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;
    }
    int m1 = median(arr1,n);
    int m2 = median(arr2,n);
    if(m1==m2)
        return m1;
    /* if m1 < m2 then median must  
    exist in ar1[m1....] and 
    ar2[....m2] */
    if(m1<m2)
    {
        if(n%2==0) //we need to include both the ,median elements
            return median_sorted_arrays(arr1 + (n/2) -1, arr2, n-n/2 +1);
        return median_sorted_arrays(arr1+(n/2),arr2,n-n/2);
    }
    /* if m1 > m2 then median must  
    exist in ar1[....m1] and  
    ar2[m2...] */
    else
    {
        if(n%2==0)
            return median_sorted_arrays(arr1,arr2+(n/2)-1,n-(n/2)+ 1);
        return median_sorted_arrays(arr1,arr2+(n/2),n-(n/2));
    }
        
}

int main()
{
    int ar1[] = {1, 2, 3, 6}; 
    int ar2[] = {4, 6, 8, 10}; 
    int n1 = sizeof(ar1) /  
             sizeof(ar1[0]); 
    int n2 = sizeof(ar2) /  
             sizeof(ar2[0]);
    if(n1==n2)
        cout<<"Median for same sized arrays is : "<<median_sorted_arrays(ar1,ar2,n1)<<"\n";
    else
        cout<<"Enter arrays of same size \n";
    return 0; 
}