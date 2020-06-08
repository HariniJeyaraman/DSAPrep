/*
973. K Closest Points to Origin
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
*/

#include<queue>

// Using a priority queue for Min Heap, that holds the square of the distance and the coordinates as a pair.
// The priority queue is ordered/sorted by first (in our case the sq of the distance).
// The top k elements are added to the result and returned.
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater< pair<int, vector<int>> >> sq_dist;
        vector<vector<int>> result;
        if(points.size()==0)
            return result;
        for(int i=0;i<points.size();i++)
        {
            sq_dist.push(make_pair(((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])), points[i]));
        }
        while(!sq_dist.empty() && k>0)
        {
            vector<int> temp;
            result.push_back(sq_dist.top().second);
            k--;
            sq_dist.pop();
        }
        return result;
    }
};