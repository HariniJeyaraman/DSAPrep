#include<iostream>
#include<cstdlib>
#include<set>
//1<=n<=1000
int a[1005];
int main()
{
    int n;
    std::set<int> st;
    std::cout<<"Enter the number of elements : ";
    std::cin>>n;
    for(int i=0;i<n;++i)
    {
        std::cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        st.insert(a[i]);
    }
    std::set<int> :: iterator it;
    for(it=st.begin();it!=st.end();it++)
    {
        std::cout<< *it<<"\n";
    }

    std::cout<<"Number of distinct elements : "<< st.size()<<"\n";
    it = st.find(3);
    //If the element is not found, it will return the last element
    if(it!=st.end())
    {
        std::cout<<*it<<"\n";
    }
    else
        std::cout<<"Element not found in set \n";
    return 0;

}