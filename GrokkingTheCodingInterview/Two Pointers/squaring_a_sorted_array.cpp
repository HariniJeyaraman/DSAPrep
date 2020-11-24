/*
Squaring a Sorted Array (easy)
Problem Statement #
Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9]
*/

#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

/*
We can just square each element and sort the squared array. But this takes O(n logn)
So we use a 2 pointer technique to reduce the time complexity to O(n)
Since the numbers at both the ends can give us the largest square, an alternate approach could be to use two pointers
starting at both the ends of the input array.
At any step, whichever pointer gives us the bigger square we add it to the result array and move to the next/previous number according to the pointer.
*/

vector<int> sortedSquare(vector<int> a){
vector<int> result(a.size());
int left = 0, right = a.size()-1, ind = a.size()-1;
while(left<=right){
    if(a[left]*a[left]>a[right]*a[right]){
        result[ind] = a[left]*a[left];
        ind--;
        left++;
    }
    else{
        result[ind] = a[right]*a[right];
        ind--;
        right--;
    }
}

return result;
}

int main(){
    vector<int> res = sortedSquare({-2,-1,0,2,3});
    for(int val : res) cout<<val<<" ";
    cout<<endl;
    res = sortedSquare({-3,-1,0,1,2});
    for(int val : res) cout<<val<<" ";
    cout<<endl;
    return 0;
}