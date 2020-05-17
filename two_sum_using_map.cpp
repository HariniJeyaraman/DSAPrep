/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based.
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(vector<int> a, int k)
{
    map<int,int> m;
    vector<int> result;
    if(a.size()<2)
        return result;
    for(int i=0;i<a.size();i++)
    {
        int pair=k-a[i];
        if(m.find(pair)!=m.end()) //that is pair has been found in the map
        {
            result.push_back(m[pair]+1); //m[pair] will give the value of the key "pair"
            result.push_back(i+1);
        }
        if(m.find(a[i])==m.end()) //the element of array is not present in the map
            m[a[i]]=i; //adding the element as key and its index as value

    }
    return result;
}

int main()
{
    vector<int> a={2, 11, 7, 15};
    cout<<"The positions are : \n";
    vector<int> res = twoSum(a, 9);
    for(int el : res)
        cout<<el<<" ";
    cout<<endl;
    return 0;
}