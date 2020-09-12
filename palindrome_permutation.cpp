/*
266. Palindrome Permutation
Easy

Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> m;
        for(char c : s){
            m[c]++;
        }
        int c=0,d=0;
        for(auto &val:m){
            if(s.length()%2==0){
               if(val.second%2!=0)
                return false;
            }
            if(s.length()%2==1){
              if(val.second%2==1)
                d++;
              if(d>1)
                  return false;
            } 
        }
        return true;
        
    }
};