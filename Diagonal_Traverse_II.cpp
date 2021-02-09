/*
1424. Diagonal Traverse II
Medium
Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.

Example 1:

Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]

Example 2:

Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]

Example 3:

Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: [1,4,2,5,3,8,6,9,7,10,11]

Example 4:

Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        set<int> s;
        map<int, vector<int>> m;
        for(int i=n-1;i>=0;i--){
            for(int j=nums[i].size()-1;j>=0;j--){
                m[i+j].push_back(nums[i][j]);
                s.insert(i+j);
            }
        }
        vector<vector<int>> result;
        for(int i=0;i<s.size();i++){
            result.push_back(m[i]);
        }

        vector<int> flatten;
        for(auto id : result){
            for(int val : id){
                flatten.push_back(val);
            }
        }
        return flatten;
    }
};
