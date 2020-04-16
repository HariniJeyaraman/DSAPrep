#include<iostream>
#include<cstdlib>
#include<algorithm>

struct data
{
    std::string name;
    int marks;
};
data a[100];

int compare(data a, data b)
{
    if(a.marks!=b.marks)
        return a.marks<b.marks;
    //If 2 people have the same marks, print the person whose name is lexicographically smaller first
    else if(a.marks==b.marks)
        return a.name<b.name;
}

int main()
{
    int n;
    std::cout<<"Enter the number of elements : ";
    std::cin>>n;
    std::cout<<"Enter the name and marks : \n";
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i].name;
        std::cin>>a[i].marks;
    }
    std::sort(a,a+n,compare);
    for(int i=0;i<n;i++)
    {
        std::cout<<a[i].name<<" ";
        std::cout<<a[i].marks<<"\n";
    }
}