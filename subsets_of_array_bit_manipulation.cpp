//Find all the subsets for a given array using bit manipulation
#include<iostream>
#include<cstdlib>
#include<vector>

void subset(std::vector<int> a)
{
    int n=a.size();
    std::cout<<"Size of array is : "<<n<<"\n";
    //if there are 3 elements, number of possible subsets is 2^3 = 8
    //therefore if there are n elements, number of possible subsets is 2^n
    //O(n * 2^n)
    for(int i=0;i<(1<<n);i++)
    {
        //finding binary representation of the number
        for(int j=0;j<n;j++)
        {
            if((i&(1<<j))!=0)
            {
                //checking the position in which it is 1 and printing the element in that position
                std::cout<<a[j]<<" ";
            }
                
        }
        std::cout<<"\n";
    }   
}

/*
Let a = {2, 5, 7}
There are 2^3=8 subsets possible
0 0 0 -> {}
0 0 1 -> {7}
0 1 0 -> {5}
0 1 1 -> {5, 7}
1 0 0 -> {2}
1 0 1 -> {2, 7}
1 1 0 -> {2, 5}
1 1 1 -> {2, 5, 7}
*/

int main()
{
    std::vector<int> a={2,5,7};
    subset(a);
    return 0;
}
