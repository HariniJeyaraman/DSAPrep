/*
Find All Anagrams in a String

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

class Solution {
public:
    bool isEqual(int a[], int b[])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int hash1[26]={0};
        int hash2[26]={0};
        vector<int> result;
        if(p.size()>s.size())
            return result;
        if(s.length()==0)
            return result;
        for(int i=0;i<p.size();i++)
            hash1[p[i]-'a']++;
         int left=0;
        int right=p.size()-1;
        for(int i=left;i<=right;i++)
        {
            hash2[s[i]-'a']++;
        }
        if(isEqual(hash1, hash2))
        {
            result.push_back(left);
        }
        right++;
        while(right<s.size())
        {
            // cout<<"Entered\n";
            
            hash2[s[left]-'a']--;
            left++;
            hash2[s[right]-'a']++;
            right++;
            // cout<<s[left]<<" "<<s[right]<<endl;
            if(isEqual(hash1, hash2))
            {
                // cout<<"Entered\n";
                result.push_back(left);
            }
        }
        return result;
    }
};