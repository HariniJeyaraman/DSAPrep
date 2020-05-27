/*
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order.

*/
//Using Priority Queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<int> result;
        if(k==0 || nums.size()==0)
            return result;
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        priority_queue<pair<int, int>> pq;
        map<int, int>:: iterator it;
        for(it=freq.begin();it!=freq.end();it++)
            pq.push(make_pair(it->second, it->first));
        while(!pq.empty()&&k>0)
        {
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};

//Without Priority Queue using vector<pair<int, int>>
class Solution {
public:
     static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if(a.first>b.first)
            return true;
        return false;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<int> result;
        vector<pair<int, int>> vec;
        if(k==0 || nums.size()==0)
            return result;
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
       
        map<int, int>:: iterator it;
        for(it=freq.begin();it!=freq.end();it++)
           vec.push_back(make_pair(it->second, it->first));
        sort(vec.begin(), vec.end(), comp);
        for(int i=0;i<vec.size() && i<k ;i++)
        {
            result.push_back(vec[i].second);
        }
        return result;
    }
};