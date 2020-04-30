/*
XOR of all the elements in the given range [L, R]

Given a range [L, R], the task is to find the XOR of all the integers in the given range i.e. (L) ^ (L + 1) ^ (L + 2) ^ … ^ (R)
*/
#include<iostream>
#include<cstdlib>
#include<vector>

//Linear time algo naive
//In naive method if we have q queries, we will have to compute xor for every query and time complexity will be O(n*q)
int findXOR_naive(std::vector<int> a, int L, int R)
{
    int ans=0;
    for(int i=L;i<=R;i++)
    {
        ans^=a[i];
    }
    return ans;
}

/*We store the XOR values of each element
For calculating XOR of L to R, we can get the result by doing XOR[L-1]^XOR[R]
Ex : a={1, 3, 5, 7, 8, 9}; //indexed at 1
XOR when L=3,R=5 
XOR[3]=1^3^5
XOR[3-1]=XOR[2]=1^3
XOR[5]=1^3^5^7^8 
XOR[2]^XOR[5]=(1^3) ^ (1^3^5^7^8) = (5^7^8)
*/
//If we get q queries, the time complexity will be O(n)+O(q) since we are precomputing
int findXOR(std::vector<int> a, int L, int R)
{
    std::vector<int> xor_val(a.size());
    for(int i=0;i<xor_val.size();i++)
        xor_val[i]=0;
    xor_val[0]=a[0];
    for(int i=1;i<a.size();i++)
    {
        xor_val[i]=xor_val[i-1]^a[i];
    }
    return xor_val[L-1]^xor_val[R];
}


int main()
{
    std::vector<int> a={1,2,3,4,5,6};
    std::cout<<"The XOR result is : "<<findXOR_naive(a,2,5)<<"\n";
    std::cout<<"The XOR result is : "<<findXOR(a,2,5)<<"\n";
    std::cout<<"The XOR result is : "<<(3^4^5^6)<<"\n";
    return 0;
}

