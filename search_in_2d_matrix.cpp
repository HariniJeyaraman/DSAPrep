/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

*/

//treat the 2d matrix as a 1d array. Since the matrix is row-wise sorted, if we consider it as a 1d array, it would be a sorted array, so we can
//implement the standard binary search algo to find the target element
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=(m*n)-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid/n][mid%n]==target)
                return true;
            else if(matrix[mid/n][mid%n]>target)
                high=mid-1;
            else
               low=mid+1;
        }
        return false;
    }
};