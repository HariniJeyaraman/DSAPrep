#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

// A C++ program to sort an array in wave form using 
// a sorting function 
//All even indexed elements should be greater than their previous and next element
//All odd indexed elemets should be lesser than their previous and next element

std::vector<int> wave_sort(std::vector<int> a)
{
    //sort(a,a+n);
    for(int i=0;i<a.size();i+=2)
    {
        // If current even element is smaller than previous
        if(i>0 && a[i-1]>a[i])
        {
            std::swap(a[i-1],a[i]);
        }
        // If current even element is smaller than next
        if(i<a.size()-1 && a[i+1]>a[i])
        {
            std::swap(a[i+1],a[i]);
        }
    }
    //If there are multiple answers possible, to return the one thats lexicographically smallest, first sort the array. If not needed, comment the line
    return a;
}

int main()
{
    int n;
    std::cout<<"Enter the size of the array : ";
    std::cin>>n;
    std::vector<int> a(n);
    std::cout<<"Enter the elements of the array : \n";
    for(int i=0;i<n;i++)
        std::cin>>a[i];
    std::vector<int> res = wave_sort(a);
    std::cout<<"Wave sorted array is : \n";
    for(int i=0;i<res.size();i++)
        std::cout<<res[i]<<" ";
    return 0;
}