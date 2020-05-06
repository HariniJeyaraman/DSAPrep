/*
 Given an arbitrary ransom note string and another string containing letters from all the magazines, 
 write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>

bool canConstruct(std::string ransomNote, std::string magazine) {
        int c=0;
        for(int i=0;i<ransomNote.length();i++)
        {
            for(int j=0;j<magazine.length();j++)
            {
                if(ransomNote[i]==magazine[j]){
                    magazine[j]='X';
                    c++;
                    break; //we need to look for the next character in ransomNote as this current character is found in magazine
                }
            }
        }
        if(c==ransomNote.length())
        return true;
        return false;
    
    }

int main()
{
    bool result=canConstruct("bg", "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj");
    std::cout<<"Output : "<<result<<std::endl;
    return 0;
}