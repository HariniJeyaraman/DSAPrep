/*
Problem Statement #

Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.

You can start with any tree, but once you have started you can’t skip a tree. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.

Write a function to return the maximum number of fruits in both the baskets.

Example 1:

Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']

Example 2:

Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket. 
This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']
*/

//This problem is same as Find the longest substring with exactly k distinct characters, except here, the value of k = 2

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

int longestSubstring2(vector<char> s){
    map<char,int> m;
    map<char,int>::iterator it;
    int result=INT16_MIN;
    int l=0;
    for(int r=0;r<s.size();r++){
        m[s[r]]++;
        while(m.size()>2){
            m[s[l]]--;
            if(m[s[l]]==0){
                it = m.find(s[l]);
                m.erase(it);
            }
            l++;
        }
        result = max(result,r-l+1);
    }
    return result;
}

int main(){
    cout<<longestSubstring2({'A','B','C','A','C'})<<endl;
    cout<<longestSubstring2({'A','B','C','B','B','C'})<<endl;
    return 0;
}
