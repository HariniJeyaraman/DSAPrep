/*
186. Reverse Words in a String II
Medium

Given an input string , reverse the string word by word. 

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/

class Solution {
public:
    void reverseFull(vector<char>& s){
    int l=0,r=s.size()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
    
    void reverseWords(vector<char>& s) {
        reverseFull(s);
        vector<char>temp;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' || i==s.size()-1){
                if(i==s.size()-1)
                    reverse(s.begin()+start, s.begin()+i+1);
                else
                reverse(s.begin()+start, s.begin()+i);
                start=i+1;
            }
        }
    }
};