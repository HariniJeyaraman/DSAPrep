/*
Given the array of strings A,
you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
and S2.

For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc"
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>

//We start by checking if each character in the 1st string is present in the other strings
//We iterate over every character in the 1st string, and check if that character is present in the other strings as well
std::string longestCommonPrefix(std::vector<std::string> a)
{
    std::string result="";
    if(a.size()==0)
        return result;
    for(int i=0;i<a[0].size();i++)
    {
        bool isQualified=true;
         for(int j=1;j<a.size();j++) //we need to iterate on all the strings other than the 1st, since we're comparing the 1st string with the rest
        {
            if(a[0][i]!=a[j][i] || i>=a[j].size())
            {
                isQualified=false;
                break;
            }
        }
        if(!isQualified)
            break;
        result+=a[0][i];
    }
    return result;
       
}

int main()
{
    std::vector<std::string> a={"geeksforblah", "geekekeke", "geeksmangekses"};
    std::cout<<"Longest common Prefix for the given strings is : "<< longestCommonPrefix(a)<<"\n";
}