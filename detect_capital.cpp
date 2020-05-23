/*
520. Detect Capital

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

 

Example 1:

Input: "USA"
Output: True

 

Example 2:

Input: "FlaG"
Output: False
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int up=0,low=0;
        if(isupper(word[0]))
        {
            for(int i=1;i<word.length();i++)
            {
                if(isupper(word[i]))
                    up++;
                else if(islower(word[i]))
                    low++;
            }
            if(up+1==word.length())
                return true;
            else if(low+1==word.length())
                return true;
        }
        
            for(int i=1;i<word.length();i++)
            {
                if(isupper(word[i]))
                    return false;
            }
        
        return true;
    }
};