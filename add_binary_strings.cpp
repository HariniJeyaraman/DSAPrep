//Given two binary strings, return their sum (also a binary string).
#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;
/*Input:  a = "11", b = "1"
Output: "100"*/
std::string addBinaryStrings(std::string a, std::string b)
{
    string result="";
    int i=a.size()-1;
    int j=b.size()-1;
    int carry_in=0;
    while(i>=0 && j>=0)
    {
        int a1=a[i]-'0';
        int b1=b[j]-'0';
        int sum=a1+b1+carry_in;
        carry_in=sum/2;
        result+=char((sum%2)+'0');
        i--;
        j--;
    }
    if(i!=-1)
    for(int k=i;k>=0;k--)
    {
        int sum=(a[k]-'0')+carry_in;
        result+=char((sum%2)+'0');
        carry_in=sum/2;
    }

    if(j!=-1)
    for(int k=j;k>=0;k--)
    {
        int sum=(b[k]-'0')+carry_in;
        result+=char((sum%2)+'0');
        carry_in=sum/2; 
    }
    if(carry_in==1)
    result+=char(carry_in+'0');
    reverse(result.begin(),result.end());
    return result;
}


int main()
{
    // std::string a="1010110111001101101000";
    // std::string b="1000011011000000111100110";
    std::string a="10101011";
    std::string b="110001111110101";
    std::cout<<"The sum is : \n"<<addBinaryStrings(a,b)<<"\n";
    return 0;
}