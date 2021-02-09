/*
498. Diagonal Traverse
Medium

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        int m = matrix.size();
        if(m==0) return r;
        int n = matrix[0].size();
        
        vector<vector<int>> res(m+n-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            res[i+j].push_back(matrix[i][j]);
            }
        }
        int k = m+n-1;
        for(int i=0;i<k;i++){
            if(i%2==0){
                reverse(res[i].begin(), res[i].end());
            }
        }
        for( auto el : res){
            for(int val : el){
                r.push_back(val);
            }
        }
        return r;
    }
};