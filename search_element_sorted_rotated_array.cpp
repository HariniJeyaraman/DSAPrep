//Search for a given element in a sorted, rotated array
#include<iostream>
#include<cstdlib>
#include<vector>

int find_pivot(std::vector<int> a, int beg, int end)
{
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(mid>0 && a[mid]<a[mid-1])
            return mid;
        else if(a[mid]>a[end])
            beg=mid+1;
        else
            end=mid;
    }
}

int search_element(std::vector<int> a, int key, int beg, int end)
{
    int pivot = find_pivot(a,0,a.size()-1);
    if(key>=a[pivot] && key<=a[end])
        beg=pivot;
    else
        end=pivot;
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(key==a[mid])
            return mid;
        else if(key>a[mid])
            beg=mid+1;
        else
            end=mid-1;
    }
    return -1;
}

int main()
{
    std::vector<int> a={14,15,16,19,23,6,7,8,9};
    std::cout<<"The index of element is : "<<search_element(a,7,0,a.size()-1)<<"\n";
    return 0;
}