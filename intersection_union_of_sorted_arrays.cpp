//Intersection of sorted arrays
#include<iostream>
#include<cstdlib>
#include<vector>

std::vector<int> intersection(std::vector<int> a1, std::vector<int> a2)
{
    int i=0,j=0;
    std::vector<int> result;
    while(i<a1.size() && j<a2.size())
    {
        if(a1[i]<a2[j])
            i++;
        else if(a1[i]>a2[j])
            j++;
        else
        {
            result.push_back(a1[i]);
            i++;
            j++;
        }   
            
    }
    return result;
}

std::vector<int> Union(std::vector<int> a1, std::vector<int> a2)
{
    int i=0,j=0;
    std::vector<int> result;
    while(i<a1.size() && j<a2.size())
    {
        if(a1[i]<a2[j])
        {
            result.push_back(a1[i]);
            i++;

        }
        else if(a1[i]>a2[j])
        {
            result.push_back(a2[j]);
            j++;
        }
        else
        {
            result.push_back(a1[i]);
            i++;
            j++;
        }   
            
    }
    while(i<a1.size())
        result.push_back(a1[i++]);
    while(j<a2.size())
        result.push_back(a2[j++]);
    return result;

}

int main()
{
    std::vector<int> a1 = {1,2,9,10,16,17,22,800};
    std::vector<int> a2 = {2,9,12,16,18,20,22,93,100};
    std::vector<int> result = intersection(a1,a2);
    for(int val : result)
        std::cout<<val<<" ";
    std::cout<<"\n";
    std::vector<int> result2 = Union(a1,a2);
    for(int val : result2)
        std::cout<<val<<" ";
    std::cout<<"\n";
    return 0;
}