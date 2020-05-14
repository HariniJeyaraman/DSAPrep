/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.
*/
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int binarysearch(int num)
    {
         int beg=1;
        int end=num;
        while(beg<=end)
        {
            long long mid=beg+(long)(end-beg)/2;
            if(mid*mid==num)
                return mid;
            if(mid*mid<num)
                beg=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    bool isPerfectSquare(int num) {
       int sqrt=binarysearch(num);
        if(sqrt!=-1)
            return true;
        return false;
    }

int main()
{
    cout<<"If Perfect square, 1 else 0 : "<<isPerfectSquare(6)<<endl;
    return 0;
}