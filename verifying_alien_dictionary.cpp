/*
953. Verifying an Alien Dictionary

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
*/

class Solution {
public:
    
    bool isAlienSorted(vector<string>& words, string order)
    {
        map<char, int> alien_map; //storing the new order according to alien language
        if(words.size()==1 || words.size()==0)
            return true;
        for(int i=0;i<order.length();i++)
        {
            alien_map[order[i]]=i;
        }
        
        for(int i=0;i<words.size()-1;i++)
        {
            if(!compare(words[i],words[i+1],alien_map))
                return false;
        }
        return true;
    }
    
    //custom compare function
    bool compare(string word1, string word2, map<char, int> mp)
    {
        int size=min(word1.length(),word2.length());
        for(int i=0;i<size;i++)
        {
            if(mp[word1[i]]<mp[word2[i]])
                return true;
            else if(mp[word1[i]]>mp[word2[i]])
                return false;
        }
        if(word1.length()>word2.length())
            return false;
        return true;
    }
};