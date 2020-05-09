/*
Check If It Is a Straight Line
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include <boost/math/tools/precision.hpp>

using namespace std;

bool checkStraightLine(vector<vector<int>>& a) {
        double m = (((double)a[1][1]-a[0][1])/(a[1][0]-a[0][0]));
        for(int i=1;i<a.size()-1;i++)
        {
                double slope=(((double)a[i][1]-a[i+1][1])/(a[i][0]-a[i+1][0]));
                //You should never compare floating point numbers for equality. Use a threshold for the comparison instead.
                if( abs(m-slope) > std::numeric_limits<double>::epsilon()) //comparing double datatype variables
                    return false;
        }
        return true;
    }

int main()
{
    vector<vector<int>> a={{-4,-3},{1,0},{3,-1},{0,-1},{-5,2}};
    cout<<checkStraightLine(a)<<endl;
    return 0;
}