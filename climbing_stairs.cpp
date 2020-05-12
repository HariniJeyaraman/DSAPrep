/*
You are climbing a stair case and it takes A steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input Format:

The first and the only argument contains an integer A, the number of steps.

Output Format:

Return an integer, representing the number of ways to reach the top.

Constrains:

1 <= A <= 36

Example :

Input 1:

A = 2 Output 1:

2 Explanation 1:

[1, 1], [2] Input 2:

A = 3 Output 2:

3 Explanation 2: 

[1 1 1], [1 2], [2 1]
*/
#include<iostream>
#include<cstdlib>

int climbStairs(int n)
{
    int dp[n];
        dp[0]=1;
        dp[1]=1;
        //dp[2]=2;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];//to come to the ith step 
                //you must have taken 1 or 2 steps from the previous state to reach i
        return dp[n];
}

int main()
{
    std::cout<<"Number of ways to get to the nth step is : "<<climbStairs(3)<<std::endl;
    return 0;
}