/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

//The only takeaway from this problem is to return 0 when the result overflows or underflows. This can be achieved using a simple check using INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        long long n = (long long)(x);
        long long result=0;
        long long d=0;
        while(n!=0)
        {
            long long pop = n%10;
            result=result*10+pop;
            d++;
            n/=10;
        }
        if(result>INT_MAX || result<INT_MIN)
            return 0;
        return result;
    }
};