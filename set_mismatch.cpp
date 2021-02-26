/*
645. Set Mismatch
Easy

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:

Input: nums = [1,1]
Output: [1,2]

 

Constraints:

    2 <= nums.length <= 104
    1 <= nums[i] <= 104

*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> m;
        vector<int> result;
        int n = nums.size(), missing, sum=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]==2)
                result.push_back(nums[i]);
        }
        for(auto val : m){
            sum+=val.first;
        }
        missing = (n*(n+1)/2) - sum;
        result.push_back(missing);
        return result;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> m;
        vector<int> result;
        int n = nums.size(), missing=1, dup=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(m.find(i)!=m.end()){
                if(m[i]==2){
                    dup=i;
                }
            }
            else
                missing=i;
        }
        return {dup, missing};
    }
};