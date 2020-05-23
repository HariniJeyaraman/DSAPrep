/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
*/

#include <bits/stdc++.h>
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> freq;
        string temp="",maxElement;
        int ind=0;
        // for(auto& c : paragraph)
        // {
        //    c = tolower(c);
        // }
        transform(paragraph.begin(),paragraph.end(), paragraph.begin(), ::tolower); 
        for(int i=0;i<paragraph.length();i++)
        {
           if((paragraph[i]>='a' && paragraph[i]<='z') || (paragraph[i]>='A' && paragraph[i]<='Z')&&paragraph[i]!=' ')
            {
                temp+=paragraph[i];
                ind++;
            }
            if(paragraph[i]==' ' || i==paragraph.length()-1 || paragraph[i]==',')
            {
                if(temp.size()!=0)
                freq[(temp)]++;
                ind=0;
                temp.clear();
            }
   
        }
        int max=-1,f=0;
        map<string, int>::iterator it;
        for(it=freq.begin();it!=freq.end();it++)
        {
            for(string el : banned)
            {
                if(it->first==el)
                {
                    f=-1;
                    goto label;
                }
            }
            if(it->second>max)
            {
                // cout<<"Emtered";
                max=it->second;
                maxElement=it->first;
            }
            label:;
                
        }
        return maxElement;
    }
};