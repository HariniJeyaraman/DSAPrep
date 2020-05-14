/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) 
deleted without changing the relative order of the remaining characters. 
(eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence
that is common to both strings.
*/
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int longestCommonSubsequence(string a, string b)
{
    int m=a.length();
    int n=b.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    cout<<"length is : "<<longestCommonSubsequence("AGGTAB", "GXTXAYB")<<endl;
    return 0;
}

/*
If the character at (i-1)th position of a and (j-1)th position of b are same, then update dp[i][j] as its previous dialogal element
in the previous row + 1
If they are not equal, then update dp[i][j] with the maximum of the element above it and the element to its immediate left
dp :
        A   G   G   T   A   B

    0   0   0   0   0   0   0

G   0   0   1   1   1   1   1

X   0   0   1   1   1   1   1

T   0   0   1   1   2   2   2

X   0   0   1   1   2   2   2

A   0   1   1   1   2   3   3

Y   0   1   1   1   2   3   3
                           
B   0   1   1   1   1   1   4  <---------Longest length subsequence
*/
                           