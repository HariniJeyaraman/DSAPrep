//Given a string, find the length of the longest substring in it with no more than K distinct characters.
/*
Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Example 2:

Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".

Example 3:

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

int longestSubstringk(string s, int k){
    map<char, int> m;
    map<char,int>::iterator it;
    int l=0;
    int result = INT16_MIN;
    for(int r=0;r<s.length();r++){
        m[s[r]]++;
        while(m.size()>k){
            m[s[l]]--;
            if(m[s[l]]==0){
                it = m.find(s[l]);
                m.erase(it);
            }
            l++;
        }
        result = max(result,r-l+1);
    }
    return result;
}

int main(){
    cout<<longestSubstringk("araaci",2)<<endl;
    cout<<longestSubstringk("araaci",1)<<endl;
    cout<<longestSubstringk("cbbebi",3)<<endl;

}