/*
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.
*/


void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    const int m = A.size();
    const int n = A[0].size();
    vector<bool> row_zeroes(m);
    vector<bool> col_zeroes(n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==0)
            {
                row_zeroes[i]=true;
                col_zeroes[j]=true;
            }
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(row_zeroes[i] || col_zeroes[j])
            {
                A[i][j]=0;
            }
        }
    }
    
}
