/*
56. Merge Intervals
Medium

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

//The basic idea is to sort the intervals based on the start time of each interval
//Then compare the end time , and the start time of every consecutive interval
//If the end time of the prev interval is >= start time of the next interval, there is over lapping

class Solution {
public:
    //Sorting the interval based on the start time of the intervals
    static bool custom_sort(vector<int>& a, vector<int>& b)
    {
        if(a[0]<b[0]) return true;
        return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size()<=1)
            return intervals;
        sort(intervals.begin(), intervals.end(), custom_sort);
        for(vector<int> le:intervals)
            cout<<le[0]<<" "<<le[1]<<"\t";
        cout<<"\n";
        result.push_back(intervals[0]); //Since the intervals are sorted, we push the first interval into result
        //We compare every interval (except first, since it is already added to result) with the interval end time in result
        for(int i=1; i<intervals.size();i++)
        {
            //remember to use &, so that the vector is used as pass by reference, so that the changes made to last vector
            // get reflected to the result vector 
            vector<int>& last = result.back();
            if(last[1]>=intervals[i][0])
            {
                last[1]=max(intervals[i][1], last[1]);
            }
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};