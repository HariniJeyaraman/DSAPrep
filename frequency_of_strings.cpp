//Find the frequency of strings, given a an array of strings
#include<cstdlib>
#include<iostream>
#include<map>
#include<cstring>

int main()
{
    std::string a[]={"harla", "why", "what", "harla","she","she","why","so"};
    int n=sizeof(a)/sizeof(a[0]);
    std::map<std::string,int> frequency;
    for(int i=0;i<n;i++)
        frequency[a[i]]++;
    std::map<std::string,int> :: iterator it;
    for(it=frequency.begin();it!=frequency.end();it++)
    {
        std::cout<<it->first<<" "<<it->second<<"\n";
    }
    return 0;
}