//Check if a subarray of sum 0 exists or not
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;

void zeroSumSubarray(vector<int> nums)
{
    map<int, int> sumMap;//stores the subarray sum and the last index
    vector<int> result;
    int currSum=0;
    for(int i=0;i<nums.size();i++)
    {
        currSum+=nums[i];
       
        //the same sum has been encountered before
        if(currSum==0 || sumMap.find(currSum)!=sumMap.end())
        {
            //  cout<<currSum<<endl;
            // result.push_back(sumMap[currSum]);
            // result.push_back(i);
            cout<<sumMap[currSum]+1<<" "<<i<<endl;
            // break;
        }
        if(sumMap.find(currSum)==sumMap.end())
            sumMap[currSum]=i;
    }
    // return result;
}

int main()
{
    vector<int> nums={4,2,-3,-1,0,4};
    zeroSumSubarray(nums);
    return 0;
}
