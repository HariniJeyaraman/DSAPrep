/*
454. 4Sum II
Medium

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -2^28 to 2^28 - 1 and the result is guaranteed to be at most 2^31 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> ab;
        unordered_map<int,int> cd;
        int result=0;
        //creating all possible sums from A and B and sum from C and D
        int n=A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ab[A[i]+B[j]]++;
                cd[C[i]+D[j]]++;
            }
        }
        
        for(auto &val : ab){
            if(cd.find(-1*val.first)!=cd.end()){
                result+=cd[-1*val.first]*ab[val.first];
                // int v = -1*val.first;
                // result+=val.second*cd[v];
            }
        }
        return result;
    }
};