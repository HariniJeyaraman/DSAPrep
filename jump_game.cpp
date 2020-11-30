/*
55. Jump Game
Medium

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 

Constraints:

    1 <= nums.length <= 3 * 10^4
    0 <= nums[i][j] <= 10^5

*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

//Time Limit Exceeded
bool helper(vector<int> nums, int position){
        if(position == nums.size()-1)
            return true;
        int n = nums.size();
        int maxDistanceHopped = min((position + nums[position]), n-1);
        for(int i=position+1;i<=maxDistanceHopped;i++){
            if(helper(nums, i))
                return true;
        }
        return false;
    }
    
bool canJump(vector<int> nums) {
    return helper(nums, 0);
}

//C version using array Time Limit Exceeded
bool canJump(int* nums, int numsSize){
    if(numsSize==1) return true;
    for(int i=1;i<=nums[0];i++){
        int flag = canJump(nums+i, numsSize-i);
        if(flag == true) return true;
    }
    return false;
}


bool canJump2(vector<int> nums) {
        int lastGoodIndex = nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(i + nums[i] >= lastGoodIndex)
                lastGoodIndex = i;
        }
        return lastGoodIndex == 0;
    }

int main(){
    cout<< canJump({2,3,1,1,4})<<endl;
    cout<< canJump2({2,3,1,1,4})<<endl;
    return 0;
}