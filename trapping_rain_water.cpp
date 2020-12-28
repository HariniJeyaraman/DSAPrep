/*
42. Trapping Rain Water
Hard

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

//Brute Force
class Solution {
public:
    int max_val(vector<int> &height, int beg, int end){
        int res = 0;
        for(int i=beg;i<=end;i++){
            if(height[i]>res){
                res = height[i];
            }
        }
        return res;
    }
    
    int trap(vector<int>& height) {
        int result=0, n = height.size();
        int left_max = 0, right_max = 0;
        for(int i=0;i<height.size();i++){
            // left_max = 0; right_max = 0;
            left_max = max_val(height, 0, i);
            right_max = max_val(height, i, n-1);
            result+=min(left_max, right_max) - height[i];
        }
        return result;
    }
};

//Optimized using DP to store max heights instead of recomputing heights for each iteration
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), result=0;
        if(n==0) return 0;
        int left[n], right[n];
        left[0] = height[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1], height[i]);
        }
        for(int i=0;i<n;i++){
            result+=min(left[i], right[i])-height[i];
        }
        return result;
    }
};