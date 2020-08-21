/*
567. Permutation in String
Medium

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
*/

//This is a sliding window problem
public:
    bool isEqual(int hash1[], int hash2[]){
        for(int i=0;i<26;i++){
            if(hash1[i]!=hash2[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int hash1[26]={0};
        int hash2[26]={0};
        if(s1.length()>s2.length())
            return false;
        //populating hash1 with frequency of characters in string s1
        for(int i=0;i<s1.length();i++){
            hash1[s1[i]-'a']++;
        }
        
        int r=s1.length()-1;//right pointer of sliding window
        int l=0;//left pointer of sliding window
        for(int i=l;i<=r;i++){
            hash2[s2[i]-'a']++;
        }
        if(isEqual(hash1,hash2))
            return true;
        r++;
        while(r<s2.length()){
            hash2[s2[l]-'a']--;
            l++;
            hash2[s2[r]-'a']++;
            r++;
            if(isEqual(hash1,hash2)) return true;
        }
        return false;
    }
};