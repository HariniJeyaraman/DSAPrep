/*
970. Powerful Integers
Easy

Given two positive integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.

Return a list of all powerful integers that have value less than or equal to bound.

You may return the answer in any order.  In your answer, each value should occur at most once.

Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation: 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]

Note:

1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6
*/

/*
*    x^i + y^j <=bound
*    => x^i <=bound and y^j<=bound
*    To find maximum value of i and j :
*    Taking log base x on both sides
*    logx(x^i) <= logx(bound)
*    i <= logx(bound)
*    To get maximum value of i, we must choose minimum x. x lies from  1 to 100. We cannot take base as 1. So we choose 2
*    i <= log2(10^6)
*    i <= 19.931 (approx. 20)
*    Similarly j is also at max 20
*/
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> result;
    
        for(int i=0;i<=20 && pow(x,i)<=bound;i++){
            for(int j=0;j<=20 && pow(y,j)<=bound;j++){
                if((pow(x,i)+pow(y,j))<=bound)
                    result.insert(pow(x,i)+pow(y,j));
            }
        }
        vector<int> ans;
        for(auto &val : result)
            ans.push_back(val);
        return ans;
        
    }
};