#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

//Using sorting
int check_anagram1(string s1,string s2)
{
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2)
        return 1;
    else
        return 0;
}

//Using map
int check_anagram2(string s, string t)
{
    if(s.length()!=t.length())
            return false;
        map<char, int> freq;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            freq[t[i]]--;
        }
        
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]!=0)
                return false;       
        }
        return true;
}

int main()
{
    int res = check_anagram1("cinema","iceman");
    if(res)
        cout<<"Is an anagram\n";
    else
        cout<<"Not an anagram\n";
    int res2 = check_anagram2("cinema","iceman");
    if(res2)
        cout<<"Is an anagram\n";
    else
        cout<<"Not an anagram\n";
    return 0;
}