/*
414. Third Maximum Number
Easy

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:

Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.

Example 2:

Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:

Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
       long one=LONG_MIN, two=LONG_MIN, three=LONG_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>one)
            {
                three=two;
                two=one;
                one=nums[i];
            }
            else if(nums[i]>two && nums[i]<one)
            {
                three=two;
                two=nums[i];
            }
            else if(nums[i]>three && nums[i]<two)
                three=nums[i];
        }
        cout<<three<<endl;
        return three==LONG_MIN?one:three;
    }
};