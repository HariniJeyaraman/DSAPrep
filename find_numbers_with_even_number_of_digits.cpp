/*
1295. Find Numbers with Even Number of Digits
Easy
Given an array nums of integers, return how many of them contain an even number of digits.

 

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
*/

//Lame solution
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c=0,result=0;
        for(int i=0;i<nums.size();i++)
        {
            c=0;
            int temp=nums[i];
            while(temp!=0)
            {
                c++;
                temp/=10;
            }
            if(c%2==0)
                result++;
        }
    return result;
    }
};

//Better solution
#include<math.h>
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto const num : nums){
            if(((int(log10(num)+1)) % 2) == 0){
            count++;
            }
        }
        return count;
    }
};