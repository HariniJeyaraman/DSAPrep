/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int maxArea1(vector<int>& height) 
{
    int max_area=0;
    for(int i=0;i<height.size();i++)
    {
        for(int j=i+1;j<height.size();j++)
        {
            max_area=max(max_area, min(height[i],height[j])*(j-i));
        }
    }
    return max_area;
        
}

int maxArea2(vector<int>& height)
{
    int max_area=0;
        int i=0,j=height.size()-1;
        while(i<j)
        {
            max_area=max(min(height[i],height[j])*(j-i), max_area);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return max_area;
}

int main()
{
    vector<int> a={1,8,6,2,5,4,8,3,7};
    cout<<"Maximum area of container : "<<maxArea1(a)<<endl;
    cout<<"Maximum area of container : "<<maxArea2(a)<<endl;
    return 0;
}