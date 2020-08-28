/*
387. First Unique Character in a String
Easy

Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

Note: You may assume the string contains only lowercase English letters.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26]={0};
        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(hash[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};

//Lame solution
class Solution {
public:
    int firstUniqChar(string a) {
        int flag=0;
        for(int i=0;i<a.length();i++)
        {
            flag=0;
            for(int j=0;j<a.length();j++)
            {
                if(i!=j && a[i]==a[j])
                {
                    flag=-1;
                    break;
                }
            }
            if(flag==0)
                return i;
        }
        return -1;
    }
};