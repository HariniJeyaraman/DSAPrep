/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        //finding the transpose of the matrix
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i!=j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        //all we have to do now is to reverse each row
        //similar to the two pointer technique to reverse an array
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};