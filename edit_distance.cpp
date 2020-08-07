/*
72. Edit Distance
Hard

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

//We use Dynamic Programming to find the minimum number of operations to convert word1 to word2
//Operations : 1) Insert a character 2) Delete character 3) Replace character
//We try to find out some pattern while filling in the DP 2D array

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n = word2.length();
        int dp[m+1][n+1];
        
        for(int i=0;i<=m;i++)
            dp[i][0]=i;
        for(int i=0;i<=n;i++)
            dp[0][i]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
            }
        }
        
        return dp[m][n];
    }
};

/*
Ex : word1 : "horse" and word2 : "ros"
This is the 2D DP array we use :
                     r   o   s
                 0	 1	 2	 3	--> (0,0) : Null -> Null - 0 opn; (0,1) : Null -> r - 1 opn; (0,2) : Null -> ro - 2 opn; (0,3) : Null -> ros : 3 opn
            h    1	 1	 2	 3	--> (1,0) : h -> Null - 1 opn; (1,1) : h->r : 1 opn; (1,2) : h->ro - 2 opn;
            o    2	 2	 1	 2	
            r    3	 2	 2	 2	
            s    4	 3	 3	 2	
            e    5	 4	 4	 3	

            Replace (i-1,j-1)      Remove (i-1,j) (downwards)
            
            insert (i,j-1) (---->)
*/