/*
243. Shortest Word Distance
Easy

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int s=-1,e=-1,minDist=words.size();
        if(words.size()==0)
            return -1;
        for(int i=0;i<words.size();i++){
            if(words[i]==word1){
                s=i;
            }
            else if(words[i]==word2){
                e=i;
            }
            if(e!=-1 && s!=-1)
            minDist=min(minDist,abs(e-s));
        }
        return minDist;
    }
};