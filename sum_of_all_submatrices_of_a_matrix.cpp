/*
Sum of all Submatrices of a Given Matrix
Given a NxN 2-D matrix, the task to find the sum of all the submatrices.
*/
#include<iostream>
#include<cstdlib>

using namespace std;
//Instead of calculating all possible submatrices, we find the contribution of each element to the final sum
// Contribution of each cell = value of that cell * number of submatrices that cell will be  part of
//Summation of contribution of all cells gives us the sum of all submatrices in a given matrix
int sumOfSubmatrix(int **arr, int n, int m){
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //top left
            int tl = (i+1)*(j+1);
            int br = (n-i)*(m-j);
            sum+=arr[j][j]*tl*br;
        }
    }
    return sum;
}


int main(){
    int n,m;
    cin>>n>>m;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<sumOfSubmatrix(arr, n, m);
}