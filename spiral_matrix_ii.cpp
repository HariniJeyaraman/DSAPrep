/*
59. Spiral Matrix II
Medium

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        int row=0,col=0,row_end=n-1,col_end=n-1;
        int number=1;
        while(row<=row_end && col<=col_end){
        for(int i=col;i<=col_end;i++){
            (matrix[row][i])=number;
            number++;
        }
        row++; //since 1st row is covered
        for(int i=row;i<=row_end;i++){
            (matrix[i][col_end])=number;
            number++;
        }
        col_end--; //since last col is covered
        if(row<=row_end)
        {
            for(int i=col_end;i>=col;i--){
               (matrix[row_end][i])=number;
                number++;
            }
            row_end--;
        }
        if(col<=col_end){
            for(int i=row_end;i>=row;i--){
               (matrix[i][col])=number;
                number++;
            }
            col++;
        }
    }
        return matrix;
    }
};