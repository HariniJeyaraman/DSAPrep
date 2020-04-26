//Print matrix in Spiral form
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

void spiral(int a[3][6])
{
    int m=3;
    int n=6;
    int row_start=0,col_start=0,row_end=m-1,col_end=n-1;
    while(row_start<=row_end && col_start<=col_end)
    {
        for(int i=col_start;i<=col_end;i++)
            cout<<a[row_start][i]<<" ";
        row_start++;

        for(int i=row_start;i<=row_end;i++)
            cout<<a[i][col_end]<<" ";
        col_end--;

        if(row_start<=row_end)
        {
            for(int i=col_end;i>=col_start;i--)
                cout<<a[row_end][i]<<" ";
            row_end--;
        }

        if(col_start<=col_end)
        {
            for(int i=row_end;i>=row_start;i--)
                cout<<a[i][col_start]<<" ";
            col_start++;
        }

    }
}

int main()
{
    int a[3][6]={
            { 1, 2, 3, 4, 5, 6 }, 
            { 7, 8, 9, 10, 11, 12 }, 
            { 13, 14, 15, 16, 17, 18 }
    };
    spiral(a);
}