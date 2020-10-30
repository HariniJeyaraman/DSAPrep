/*
Problem Statement #

Given a string, find the length of the longest substring which has no repeating characters.

Example 1:

Input: String="aabccbb"
Output: 3
Explanation: The longest substring without any repeating characters is "abc".

Example 2:

Input: String="abbbb"
Output: 2
Explanation: The longest substring without any repeating characters is "ab".

Example 3:

Input: String="abccde"
Output: 3
Explanation: Longest substrings without any repeating characters are "abc" & "cde".
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int longestSubstringNoRepeat(string s){
    int result = INT16_MIN;
    int l=0;
    map<char,int> m;
    for(int r=0;r<s.length();r++){
        if(m.find(s[r])!=m.end()){
            l=max(l, (m[s[r]]+1));
        }
        m[s[r]]=r;
        result = max(result, r-l+1);
    }
    return result;
}

int main(){
    cout<<longestSubstringNoRepeat("aabccbb")<<endl;
    cout<<longestSubstringNoRepeat("abbb")<<endl;
    cout<<longestSubstringNoRepeat("abccde")<<endl;

}