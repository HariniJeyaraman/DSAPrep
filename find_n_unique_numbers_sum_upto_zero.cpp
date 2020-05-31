/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Example 2:

Input: n = 3
Output: [-1,0,1]

Example 3:

Input: n = 1
Output: [0]
*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>result;
        if(n%2==0)
        {
            for(int i=1;i<=n/2;i++)
                result.push_back(i);
            for(int i=1;i<=n/2;i++)
                result.push_back(-1*i);
        }
        else
        {   
            for(int i=1;i<=n/2;i++)
                result.push_back(i);
            for(int i=1;i<=n/2;i++)
                result.push_back(-1*i);
            result.push_back(0);
        }
        return result;
    }
};

//used a lame logic here :
//if the given number n is even, say 4 :
//the array will contain all positive numbers from 1 to n/2 that is, 1 , 2
//and negative numbers from 1 to n/2 that is, -1 and -2
//if the given number is odd,follow the same procedure and also add a zero to the array