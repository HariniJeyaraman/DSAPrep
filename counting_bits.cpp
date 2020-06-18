/*
338. Counting Bits
Medium

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]

Example 2:

Input: 5
Output: [0,1,1,2,1,2]
*/

//Using DP
/*
0 : 0000
1 : 0001
2 : 0010 //Power of 2 will have only one 1//
3 : 0011
4 : 0100 //Power of 2 will have only one 1//
5 : 0101 //No. of 1's in 4 + 1//
6 : 0110 //No. of 1's in 4 + 1//
7 : 0111 //No. of 1's in 6 + 1//
8 : 1000 //Power of 2 will have only one 1//
9 : 1001 //No. of 1's in 8 + 1//
10: 1010 //No. of 1's in 8 + 1//
11: 1011 //No. of 1's in 10 + 1//
12: 1100 //No. of 1's in 8 + 1//
13: 1101 //No. of 1's in 12 + 1//
14: 1110 //No. of 1's in 12 + 1//
15: 1111 //No. of 1's in 14 + 1//
*/

// i & (i-1) will give i with rightmost set bit unset
// number of 1's in i will be number of 1's in (i & (i-1)) + 1
class Solution {
public:
    vector<int> countBits(int num) {
       vector<int> dp(num+1);
        dp[0]=0; // 0 has no set bit
        for(int i=1;i<=num;i++)
        {
            dp[i] = dp[(i&(i-1))]+1;
        }
        return dp;
    }
};