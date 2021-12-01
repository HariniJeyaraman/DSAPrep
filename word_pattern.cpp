/*
https://leetcode.com/problems/word-pattern/discuss/1434099/C%2B%2B-0ms-or-Double-mapping-or-Well-commented

290. Word Pattern
Easy

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.


Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false

 

Constraints:

    1 <= pattern.length <= 300
    pattern contains only lower-case English letters.
    1 <= s.length <= 3000
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> m1;
        map<string, char> m2;
        vector<string> v;
        string temp = "";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            if(s[i]==' ' || i==s.length()-1){
                v.push_back(temp);
                temp.clear();
            }
        }
        if(pattern.length()!=v.size())
            return false;
        for(int i=0;i<pattern.length();i++){
            if(m1.find(pattern[i])==m1.end())
                m1[pattern[i]]=v[i];
            else{
                if(m1[pattern[i]]!=v[i]){
                    return false;
                }
            }
        }
        for(int i=0;i<v.size();i++){
            if(m2.find(v[i])==m2.end()){
                m2[v[i]]=pattern[i];
            }
            else{
                if(m2[v[i]]!=pattern[i])
                    return false;
            }
        }
        return true;
    }
};
