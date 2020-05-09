/*
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2

Output :

1
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
using namespace std;

int diffk(vector<int> a, int k)
{
    map<int, int> m;
    for(int i=0;i<a.size();i++)
    {
        if(m.find(a[i]+k)!=m.end() || m.find(a[i]-k)!=m.end())
            return 1;
        if(m.find(a[i])==m.end())
            m[a[i]]=i; 
        /*
        k is non negative, so it may become zero.
        Then, the function will give ignore the i != j condition and give false-positive.
        When inserting inside the loop, the indice of elements in s are granteed to be less than i. 
        That is because the i != j condition won't ignored in this case. 
        Assuming that, you don't have to use the indice otherwise, so using map to hold indice is not required
        */
    }
    return 0;
}

//We can even populate the map in the beginning itself, but inside the for loop we would have to take care of the condition i!=j
//In the map, we maintain the element and its index and make sure that i!=j condition holds true
int diffk_anotherway(vector<int> a, int k)
{
    map<int, int> m;
    for(int i=0;i<a.size();i++)
        m[a[i]]=i;
    for(int i=0;i<a.size();i++)
    {
        if(m.find(a[i]+k)!=m.end() &&(m.find(a[i]+k))->second !=i || m.find(a[i]-k)!=m.end() && (m.find(a[i]-k))->second !=i)
            return 1;
        // if(m.find(a[i])==m.end())
        //     m[a[i]]=i;
    }
    return 0;
}

int main()
{
    vector<int> a={1, 5, 3};
    cout<<"Result is : "<<diffk(a,2)<<endl;
    cout<<"Result is : "<<diffk_anotherway(a,2)<<endl;
    return 0;
}
