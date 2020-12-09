/*
Check if any anagram of a string is palindrome or not
We have given an anagram string and we have to check whether it can be made palindrome or not. 
Examples: 

Input : geeksforgeeks 
Output : No
There is no palindrome anagram of 
given string

Input  : geeksgeeks
Output : Yes
There are palindrome anagrams of
given string. For example kgeesseegk

*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;

//An even palindrome will have each character count of 2, an odd palindrome will have a single character count of 1
bool check_palindrome(string s){
    int n = s.length();
    int odd=0;
    map<char, int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    for(auto val : m){
        if(val.second % 2 ==1) odd++;
        if(odd>1) return false;
    }
    if(n%2==0 && odd>0) return false;
    return true;

}