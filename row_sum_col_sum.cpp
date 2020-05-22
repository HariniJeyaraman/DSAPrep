/*
Given a matrix of order m*n, the task is to find out the sum of each row and each column of a matrix.
*/
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

void row_sum(int a[4][4],int m, int n)
{
    cout<<"Row sum is : \n";
    int sum=0;
    for(int i=0;i<m;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=a[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

void col_sum(int a[4][4],int m, int n)
{
    cout<<"Column sum is :\n";
    int sum=0;
    for(int i=0;i<m;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=a[j][i];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[4][4]={ {1, 2, 3, 4}, 
                       {5, 6, 7, 8}, 
                       {9, 10, 11, 12}, 
                       {13, 14, 15, 16}};
    row_sum(arr,4,4);
    col_sum(arr,4,4);
    return 0;
}