/*
49. Group Anagrams
Medium

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> result;
        if(str.size()==0)
            return result;
        map<string, vector<string>> m;
        for(int i=0;i<str.size();i++){
            string sorted = str[i];
            sort(sorted.begin(),sorted.end());
            if(m.find(sorted)!=m.end()){
                m.insert({sorted,vector<string> ()});
            }
            m[sorted].push_back(str[i]);
        }
        
        for(auto &val : m){
            result.push_back(val.second);
        }
        return result;
    }
};