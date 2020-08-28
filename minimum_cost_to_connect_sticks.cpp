/*
1167. Minimum Cost to Connect Sticks
Medium
You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

 

Example 1:

Input: sticks = [2,4,3]
Output: 14
Example 2:

Input: sticks = [1,8,3,5]
Output: 30
*/
class Solution {
public:
    //Greedy approach by taking 2 minimums
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>, greater<int>> minHeap;
        for(int i=0;i<sticks.size();i++){
            minHeap.push(sticks[i]);
        }
        int cost=0;
        while(minHeap.size()>1){
            int temp=minHeap.top();
            minHeap.pop();
            temp+=minHeap.top();
            minHeap.push(temp);
            minHeap.pop();
            cost+=temp;
        }
        return cost;
    }
};