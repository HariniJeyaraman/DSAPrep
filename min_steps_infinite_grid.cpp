/*
You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points.
Give the minimum number of steps in which you can achieve it. You start from the first point.
*/
#include<iostream>
#include<cstdlib>
#include<vector>

int minSteps(std::vector<int> x, std::vector<int> y)
{
    int n=x.size(),dist=0;
    if (x.size() <= 1) 
        return 0;
    for(int i=0;i<n-1;i++)
    {
        dist+=std::max(abs(x[i]-x[i+1]),abs(y[i]-y[i+1]));
    }
    return dist;
}

int main()
{
    std::vector<int> x={0, 1, 1};
    std::vector<int> y={0, 1, 2};
    std::cout<<"Min distance is : "<<minSteps(x,y)<<"\n";
    return 0;

}