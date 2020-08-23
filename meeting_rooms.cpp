/*
252. Meeting Rooms
Easy

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

//If there is any overlapping interval, the person cannot attend that meeting, hence return false
class Solution {
public:
    static bool custom_sort(vector<int> a, vector<int> b){
        if(a[0]<b[0]) return true;
        return false;
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return true;
        sort(intervals.begin(), intervals.end(), custom_sort);
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>intervals[i+1][0])
                return false;
        }
        return true;
    }
};