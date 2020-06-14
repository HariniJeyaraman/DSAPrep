//Microsoft OA 2019
#include<iostream>
#include<cstdlib>
#include<vector>
#include<limits>
#include<map>
#include<algorithm>
using namespace std;

int digitSum(int n)
{
    int result=0, pop=0;
    while(n!=0)
    {
        pop=n%10;
        result=result+pop;
        n/=10;
    }
    return result;
}

int maxSum(vector<int> a)
{
    map<int, vector<int>> m;
    for(int i=0;i<a.size();i++)
    {
        int currsum=digitSum(a[i]);
        cout<<currsum<<endl;
        m[currsum].push_back(a[i]);
    }
    int result=-1;
    for(int i=0;i<a.size();i++)
    {
        vector<int> temp=m[digitSum(a[i])]; //vector containing the numbers which sum upto sum of digits of a[i]
        for(int el : temp)
        { 
            if(el!=a[i])
            {
                 
                result=max(result, a[i]+el);
            }
        }
    }
    
    // for(auto &val : m)
    // {
    //     vector<int> temp=val.second;
    //     for(auto &el:temp)
    //         cout<<el<<" ";
    //     cout<<endl;
    // }
    return result;

}

int main()
{
    vector<int> nums = {51, 71, 17, 42};
    cout<<maxSum(nums);
}
