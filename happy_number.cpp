/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

class Solution {
public:
    bool isHappy(int n) {
     //this set is to store all the values of the sums of squares of digits. If the same sum occurs again, we come to know
     //that the sum is repeating and the sum will never become 1. So we return false
     //without this hash set we will run into an infinite loop if the input is not a happy number.
     //We need to have a condition to break the loop if the input is not a happy number
      unordered_set<int> seen{};
        long long res=0,pop=0;
        while(res!=1)
        {
            res=0;
            while(n>0)
            {
                pop=n%10;
                res+=(pop*pop);
                n/=10;
            }
            
            if(seen.find(res)!=seen.end())
                return false;
            seen.insert(res);
            n=res;
            
        }
        return true;
    }
};