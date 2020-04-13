//Find the minimum element in a sorted rotated array
//We use a modified binary search to find the minimum element
#include<iostream>
#include<cstdlib>
#include<vector>

/*
int find_minimum(std::vector<int> a, int beg, int end)
{
    int mid=(beg+end)/2;
    while(beg<end)
    {
        if(a[mid]>a[end])
        {
            beg=mid+1;
        }  
        else 
        {
            end=mid;
        }
        mid=(beg+end)/2;
    }
    return a[mid];
}*/

int find_minimum(std::vector<int> a, int beg, int end)
{
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(mid>0 && a[mid]<a[mid-1])
            return a[mid];
        else if(a[mid]>a[end])
            beg=mid+1;
        else
            end=mid-1;
    }
}
int main()
{
    std::vector<int> a={6,8,9,10,14,16,19,111,0,1,2,3,4,5};
    std::cout<<"Min is : "<<find_minimum(a,0,a.size()-1)<<"\n";
    return 0;
}