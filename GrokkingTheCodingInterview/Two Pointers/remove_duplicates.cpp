/*
Remove Duplicates (easy)
Problem Statement

Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return the new length of the array.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].

Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].
*/
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> a){
    int ind=1;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]!=a[i+1])
            a[ind++] = a[i+1];
    }
    return ind;
    
}

int main(){
    cout<<removeDuplicates({2,3,3,3,6,9,9})<<endl;
    cout<<removeDuplicates({2,2,2,11})<<endl;
    return 0;
}