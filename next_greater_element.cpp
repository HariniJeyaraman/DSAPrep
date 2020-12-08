/*
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Examples:

    For any array, rightmost element always has next greater element as -1.
    For an array which is sorted in decreasing order, all elements have next greater element as -1.
    For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.

Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1

d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.

  Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;

//Naive solution
int * printNGE(int a[], int n){
    int next, f=0;
    int * result = new int[n];
    for(int i=0;i<n;i++){
        f=0;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                f=1;
                result[i] = a[j];
                break;
            }
        }
        if(f==0) result[i]=-1;
    }
    return result;
}

int * printNGEStack(int a[], int n){
    int * result = new int[n];
    stack<pair<int,int>> s;
    s.push(make_pair(a[0],0));
    for(int i=1;i<n;i++){
        if(s.empty()){
            s.push(make_pair(a[i],i));
            continue;
        }
        while(!s.empty() && a[i]>s.top().first){
            result[s.top().second] = a[i];
            s.pop();
        }
        s.push(make_pair(a[i],i));
    }
    while(!s.empty()){
        result[s.top().second] = -1;
        s.pop();
    }

    return result;
    
}

int main(){
    int a[] = {4, 5, 2, 25};
    int n = sizeof(a)/sizeof(a[0]);
    int * res = new int[n];
    res = printNGE(a,n);
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<endl;
    res = printNGEStack(a,n);
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}