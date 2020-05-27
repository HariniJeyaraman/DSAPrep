/*
692. Top K Frequent Words
iven a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Input words contain only lowercase letters.

Follow up:

    Try to solve it in O(n log k) time and O(n) extra space.
*/

//Initially we may want to find the frequency of each word using a map, then push all the entries of the map
//to a priority queue (max heap) , which will automatically sort the entries based on the frequencies and we can
//pop the first k words. But if some words have the same frequency, those words will not be sorted alphabetically.
//So we create a custom sort function to compare each word. For this, we use vector<pair<int, string>>

#include<vector>
#include<map>
#include<queue>
class Solution {
public:
    static bool comp(pair<int, string> a, pair<int, string> b)
    {
        if((a.first>b.first) || ((a.first==b.first) && (a.second<b.second)))
            return true;
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        int ind=0;
        vector<string> result(k);
        //we will perform our custom sort on this vector and after the sort, push the 1ts k elements to the result vector
        vector<pair<int, string>> vec;
        map<string, int> freq;
        //finding the frequency of each word using map
        for(int i=0;i<words.size();i++)
            freq[words[i]]++;
        map<string, int>:: iterator it;
        for(it=freq.begin();it!=freq.end();it++)
        {
            vec.push_back(make_pair(it->second, it->first));
        }
        sort(vec.begin(), vec.end(), comp);
        for(int i=0;i<vec.size() && i<k;i++)
            result[ind++]=(vec[i].second);
        return result;
    }
    
};
