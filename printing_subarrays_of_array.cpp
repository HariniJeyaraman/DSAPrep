//Printing subarrays of an array using recursion
#include<iostream>
#include<cstdlib>
#include<vector>

int a[105];
int n;

void subarray(int index, std::vector<int> v)
{

    if(index==n)
    {
        for(int i=0;i<v.size();i++)
        {
            std::cout<<v[i]<<" ";
        }
        std::cout<<"\n";
        return;
    }
    subarray(index+1,v); //either we do not choose to include the element
    v.push_back(a[index]);
    subarray(index+1,v); //or we choose to include the element
}

int main()
{
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
    std::vector<int> v;
    subarray(0,v);
}